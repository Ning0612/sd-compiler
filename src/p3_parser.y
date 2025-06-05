%{
#include "SemanticAnalyzer.hpp"
#include "Context.hpp"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 
#include <fstream>
#include <filesystem>

extern int  yylex();
extern int  yylineno;
extern FILE* yyin;

Context* ctx = nullptr;

void yyerror(const char* s){
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}
%}
/* ---------- token type ---------- */
%union{
    int ival;
    float fval;
    bool bval;
    std::string* sval;
    Type* type;
    Symbol* symbol;
    VarInit* var_init_;
    ExprInfo* expr_info;

    std::vector<Symbol>* symbol_list;
    std::vector<ExprInfo>* expr_info_list;
}

/* ---------- Keywords / Constants / Identifiers ---------- */
%token                BOOL_TOK FLOAT_TOK DOUBLE_TOK INT_TOK CHAR_TOK STRING_TOK VOID_TOK
%token                IF ELSE DO WHILE FOR FOREACH RETURN
%token                CONST PRINT PRINTLN READ TRUE FALSE
%token <sval>         ID
%token <ival>         INT_LIT
%token <fval>         REAL_LIT
%token <sval>         STRING_LIT
%token <bval>         BOOL_LIT         

%type <type> type_spec
%type <symbol> param
%type <symbol> const_decl
%type <symbol_list> param_list
%type <symbol_list> param_list_opt
%type <expr_info> func_call
%type <expr_info> const_lit
%type <expr_info> expression
%type <symbol> lvalue
%type <expr_info_list> arg_list
%type <expr_info_list> arg_list_opt
%type <var_init_> var_init

/* ---------- Operators / Delimiters ---------- */
%token                LE GE EQ NEQ LT GT
%token                PLUS MINUS MUL DIV MOD ASSIGN NOT
%token                AND OR INC DEC
%token                DOT COMMA COLON SEMICOLON 
%token                LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

%token BREAK CONTINUE SWITCH CASE DEFAULT EXTERN

// CHAR

/* ---------- Operator Precedence (Lowest to Highest) ---------- */
%left   OR                      /* || */
%left   AND                     /* && */
%nonassoc IFX                   /* if */
%nonassoc ELSE                  /* else */
%right  NOT                     /* !x */
%nonassoc LT LE GT GE EQ NEQ    /* < <= > >= == != */
%left   PLUS MINUS              /* + - */
%left   MUL DIV MOD             /* * / % */
%right  INC DEC UPLUS UMINUS    /* ++ -- */
%right  POSTINC POSTDEC         /* POST ++ -- */
%right  ASSIGN                  /* =  */

%start program // start symbol

%% 
/* ---------- Grammar Rules ---------- */

/* Program Rule */
program
    : global_decl_list {
        Symbol* mainFunc = ctx->symTab.lookup("main");
        if (mainFunc == nullptr) {
            SemanticError("missing main function", yylineno);
        }

        if (!mainFunc->type->isFunc()) {
            SemanticError("main function must be function", yylineno);
        }

        if (mainFunc->type->ret->base != BK_Void) {
            SemanticError("main function must be void", yylineno);
        }

        ctx->symTab.leaveScope();
        printf("\n");
    }
    ;

global_decl_list
    : /* empty */
    | global_decl_list global_decl
    ;

/* Declarations */
global_decl
    : const_decl
    | var_decl
    | func_decl     
    ;

local_decl
    : const_decl
    | var_decl       
    ;

/* Constant Declaration */
const_decl
    :
    CONST type_spec ID ASSIGN expression SEMICOLON {
        std::string id = *$3; delete $3;
        ExprInfo value = *$5; delete $5;
        tryDeclareConstant(ctx->symTab, id, $2, value, yylineno);
    }
    ;

/* Variable Declaration */
var_decl
    : type_spec var_init_list SEMICOLON 
    ;

var_init_list
    : var_init{
        VarInit varInit = *$1; delete $1;
        tryDeclareVarable(ctx->symTab, varInit, ctx->nowType, yylineno);
        
        if (ctx->symTab.getCurrentScopeIndex() == 0) {
            std::string declaration = "    field static ";
            switch (ctx->nowType->base) {
                case BK_Int: declaration += "int " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""; break;
                case BK_Float: declaration += "float " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"; break;
                case BK_Bool: declaration += "int " + varInit.name + " = " + (varInit.iVal ? "1" : "0"); break;
                default: SemanticError("unsupported type for static variable", yylineno); break;
            }

            ctx->fileContent.insert(ctx->fileContent.begin() + 2, declaration);
        } else {
            int index = ctx->symTab.lookup(varInit.name)->index;
            switch (varInit.valueKind) {
                case VK_Int:
                    ctx->fileContent.push_back("        sipush " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""); break;
                case VK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"); break;
                case VK_Bool:
                    ctx->fileContent.push_back("        sipush " + std::string(varInit.iVal ? "1" : "0")); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }

            switch (ctx->nowType->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                case BK_Float:
                    ctx->fileContent.push_back("        fstore " + std::to_string(index)); break;
                case BK_Bool:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }
        }
    }
    | var_init_list COMMA var_init {
        VarInit varInit = *$3; delete $3;
        tryDeclareVarable(ctx->symTab, varInit, ctx->nowType, yylineno);

        if (ctx->symTab.getCurrentScopeIndex() == 0) {
            std::string declaration = "    field static ";
            switch (ctx->nowType->base) {
                case BK_Int: declaration += "int " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""; break;
                case BK_Float: declaration += "float " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"; break;
                case BK_Bool: declaration += "int " + varInit.name + " = " + (varInit.iVal ? "1" : "0"); break;
                default: SemanticError("unsupported type for static variable", yylineno); break;
            }

            ctx->fileContent.insert(ctx->fileContent.begin() + 2, declaration);
        } else {
            int index = ctx->symTab.lookup(varInit.name)->index;
            switch (varInit.valueKind) {
                case VK_Int:
                    ctx->fileContent.push_back("        sipush " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""); break;
                case VK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"); break;
                case VK_Bool:
                    ctx->fileContent.push_back("        sipush " + std::string(varInit.iVal ? "1" : "0")); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }

            switch (ctx->nowType->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                case BK_Float:
                    ctx->fileContent.push_back("        fstore " + std::to_string(index)); break;
                case BK_Bool:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }
        }
    }
    ;

var_init
    : ID                     { $$ = new VarInit(*$1, ctx->nowType); delete $1; }  
    | ID ASSIGN expression   {
        std::string id = *$1; delete $1;
        ExprInfo expr = *$3; delete $3;

        if (!expr.isValid) {
            $$ = makeInvalidVar();
        }else{
            if (expr.type->isFunc()) {
                SemanticError("assignment from function", yylineno);
            }

            if (!expr.isConst) {
                SemanticError("assignment from non-constant", yylineno);
            }
            $$ = new VarInit(id, expr);
        }
    }
    ;

/* Function Declaration */
func_decl
    : type_spec ID LPAREN param_list_opt RPAREN LBRACE {
        ctx->returnsExpr.clear();
        ctx->funcType = $1;

        std::string funcName = *$2; delete $2;
        std::vector<Symbol> paramList = *$4; delete $4;

        std::string declaration = "    method public static " + baseKindToJavaStr($1->base) + " " + funcName + "(";
        for (size_t i = 0; i < paramList.size(); ++i) {
            if (i > 0) declaration += ", ";
            declaration += "int";
        }

        declaration += ")";

        ctx->fileContent.push_back(declaration);
        ctx->fileContent.push_back("    max_stack 15");
        ctx->fileContent.push_back("    max_locals 15");
        ctx->fileContent.push_back("    {");

        declareFunction(funcName, $1, paramList, ctx->typePool, ctx->symTab, yylineno);
    } block_items_opt RBRACE {
        if (ctx->returnsExpr.empty()) {
            SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : ctx->returnsExpr) {
            if (!expr.first.isValid) {
                break;
            }

            if (!$1->isCompatibleWith(*expr.first.type)) {
                SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible($1->base, expr.first.type->base)) {
                SemanticWarning("implicit conversion from " + baseKindToStr(expr.first.type->base) + " to " + baseKindToStr($1->base), expr.second);
            }
        }

        ctx->fileContent.push_back("    }");
        ctx->fileContent.push_back("");
        ctx->symTab.leaveScope();
    }
    | VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE {
        ctx->returnsExpr.clear();

        std::string funcName = *$2; delete $2;
        std::vector<Symbol> paramList = *$4; delete $4;

        if (funcName == "main") {
            ctx->fileContent.push_back("    method public static void main(java.lang.String[])");
        }else {
            std::string declaration = "    method public static void " + funcName + "(";

            for (size_t i = 0; i < paramList.size(); ++i) {
                if (i > 0) declaration += ", ";
                declaration += "int";
            }
            declaration += ")";

            ctx->fileContent.push_back(declaration);
        }
        
        ctx->fileContent.push_back("    max_stack 15");
        ctx->fileContent.push_back("    max_locals 15");
        ctx->fileContent.push_back("    {");

        declareFunction(funcName, ctx->typePool.make(BK_Void), paramList, ctx->typePool, ctx->symTab, yylineno);
    } block_items_opt RBRACE {
        if (!ctx->returnsExpr.empty()) {
            SemanticError("void function should not return value", yylineno);
        }

        ctx->symTab.leaveScope();

        ctx->fileContent.push_back("       return");
        ctx->fileContent.push_back("    }");
        ctx->fileContent.push_back("");
    }
    ;

/* Function Parameters */
param_list_opt:
    /* empty */ {
        $$ = new std::vector<Symbol>();
    }
    | param_list {
        $$ = $1;
    }
    ;

param_list
    : param {
        $$ = new std::vector<Symbol>;
        $$->push_back(*$1);
        delete $1;
    }
    | param_list COMMA param {
        $$ = $1;
        $$->push_back(*$3);
        delete $3;
    }
    ;

param
    : type_spec ID {
        std::string id = *$2; delete $2;
        $$ = new Symbol(id, $1, false);
    }
    ;

/* Block and Statements */
block
    : LBRACE {
        ctx->symTab.enterScope();
    } block_items_opt RBRACE {
        ctx->symTab.leaveScope();
    }
    ;

block_items_opt
    :/* empty */
    | block_items
    ;

block_items
    : block_items block_item
    | block_item
    ;

block_item
    : local_decl        
    | statement
    ;

statement
    : simple_stmt
    | if_stmt
    | loop_stmt
    | return_stmt
    | proc_call SEMICOLON
    | block
    ;

/* Simple Statements */
simple_stmt
    : assign_stmt
    | PRINT expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        if (expr.isValid) checkPrint(expr, yylineno);
        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");

        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        sipush " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        sipush " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        }
    }
    | PRINTLN expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        sipush " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        sipush " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");

            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        }
    }
    | READ lvalue SEMICOLON {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
        SemanticError("read statement not supported in code generation", yylineno);
    }
    | lvalue INC SEMICOLON {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;        
        if (expr.isValid) checkIncDecValid("increment", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
     }
    | lvalue DEC SEMICOLON {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("decrement", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
    }
    | INC lvalue SEMICOLON {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("increment", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
     }
    | DEC lvalue SEMICOLON {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("decrement", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
    }
    | SEMICOLON
    ;

assign_stmt
    : lvalue ASSIGN expression SEMICOLON {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo target = *exprPtr; delete exprPtr;
        ExprInfo value = *$3; delete $3;
        if (target.isValid && value.isValid) {
            checkAssignment(target, value, yylineno);
        }
    }
    ;

/* Lvalue Access */
lvalue
    : ID {
        std::string id = *$1; delete $1;
        Symbol* symbol = ctx->symTab.lookup(id);

        if (symbol == nullptr) {
            SemanticError("undeclared identifier: " + id, yylineno);
            $$ = nullptr;
        } else {
            $$ = symbol;
        }
    }
    ;

/* If Statement */
if_stmt
    : IF LPAREN expression RPAREN statement %prec IFX {
        ExprInfo expr = *$3; delete $3;
        if (expr.isValid) checkBoolExpr("if", expr, yylineno);
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        ExprInfo expr = *$3; delete $3;
        if (expr.isValid) checkBoolExpr("if", expr, yylineno);
    }
    ;

/* Loop Statements */
loop_stmt
    : WHILE LPAREN expression RPAREN statement{ 
        ExprInfo expr = *$3; delete $3;
        if (expr.isValid) checkBoolExpr("while", expr, yylineno); 
    }
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON {
        ExprInfo expr = *$5; delete $5;
        if (expr.isValid) checkBoolExpr("do while", expr, yylineno);
    }
    | FOR LPAREN for_simple_opt SEMICOLON expression SEMICOLON for_simple_opt RPAREN statement{
        ExprInfo expr = *$5; delete $5;
        if (expr.isValid) checkBoolExpr("for", expr, yylineno);
    }
    | FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement{
        ExprInfo from = *$5; ExprInfo to = *$8; delete $5; delete $8;
        std::string id = *$3; delete $3;
        if (from.isValid && to.isValid) {
            checkForeachRange(from, to, yylineno);
        }
        checkForeachIndex(ctx->symTab.lookup(id), yylineno);
    }
    ;

/* For Loop Optional Statements */
for_simple_opt
    : /* empty */
    | for_simple_item
    | for_simple_opt COMMA for_simple_item
    ;

for_simple_item
    : assign_no_semi
    | PRINT  expression  {
        ExprInfo expr = *$2; delete $2;
        if (expr.isValid) checkPrint(expr, yylineno);

        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        sipush " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        sipush " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        }
    }
    | PRINTLN expression  {
        ExprInfo expr = *$2; delete $2;
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        sipush " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        sipush " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        }
    }
    | READ lvalue  {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
    }
    | lvalue INC  {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("increment", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
     }
    | lvalue DEC  {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("decrement", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
    }
    | INC lvalue  {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("increment", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        iadd");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fadd");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
     }
    | DEC lvalue  {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkIncDecValid("decrement", expr, yylineno);
        if (sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        putstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        putstatic float " + sym->name);
                }
            }
            else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        sipush 1");
                    ctx->fileContent.push_back("        isub");
                    ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                    ctx->fileContent.push_back("        ldc 1.0f");
                    ctx->fileContent.push_back("        fsub");
                    ctx->fileContent.push_back("        fstore " + std::to_string(sym->index));
                }
            }
        }
     }
    ;

assign_no_semi
    : lvalue ASSIGN expression {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo target = *exprPtr; delete exprPtr;
        ExprInfo value = *$3; delete $3;
        if (target.isValid && value.isValid) {
            checkAssignment(target, value, yylineno);
        }
    }
    ;

/* Return Statement */
return_stmt
    : RETURN expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        ctx->returnsExpr.push_back(std::make_pair(expr, yylineno));

        if (expr.isConst) {
            switch (ctx->funcType->base) {
            case BK_Int:
                ctx->fileContent.push_back("        sipush " + std::to_string(expr.iVal));
                ctx->fileContent.push_back("        ireturn");
                break;
            case BK_Float:
                ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                ctx->fileContent.push_back("        freturn");
                break;
            case BK_Bool:
                ctx->fileContent.push_back("        sipush " + std::string(expr.bVal ? "1" : "0"));
                ctx->fileContent.push_back("        ireturn");
                break;
            default:
                SemanticError("unsupported return type", yylineno);
            }
        }
    }
    ;

/* Expressions */
expression
    : expression PLUS expression {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }else {
            bool isStringConcat = (lhs.type->base == BK_String && rhs.type->base == BK_String);

            if (isStringConcat) {
                $$ = concatStringResult(lhs, rhs, ctx->typePool, yylineno);
            } else {
                $$ = numericOpResult(OPADD, lhs, rhs, ctx->typePool, yylineno);
            }
        }
    }
    | expression MINUS expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPSUB, lhs, rhs, ctx->typePool, yylineno);
        }
    }
    | expression MUL   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPMUL, lhs, rhs, ctx->typePool, yylineno);
        }
    }
    | expression DIV   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPDIV, lhs, rhs, ctx->typePool, yylineno);
        }
    }
    | expression MOD   expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPMOD, lhs, rhs, ctx->typePool, yylineno);
        }
    }
    | expression LT    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPLT, lhs , rhs, ctx->typePool, yylineno);
        }
    }
    | expression LE    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPLE, lhs , rhs, ctx->typePool, yylineno);
        }
    }
    | expression GT    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPGT, lhs , rhs, ctx->typePool, yylineno);
        }
    }
    | expression GE    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPGE, lhs , rhs, ctx->typePool, yylineno);
        }
    }

    | expression EQ    expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = eqOpResult(true, lhs, rhs, ctx->typePool, yylineno);
        }
    }
    | expression NEQ   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = eqOpResult(false, lhs, rhs, ctx->typePool, yylineno);
        }
    }

    | expression AND   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = boolOpResult(true, lhs , rhs, ctx->typePool, yylineno);
        }   
    }
    | expression OR expression      {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = boolOpResult(false, lhs , rhs, ctx->typePool, yylineno);
        }
    }
    | NOT expression                {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = notOpResult(expr, ctx->typePool, yylineno);
        }
    }
    | MINUS expression %prec UMINUS {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = unaryOpResult(true, expr, yylineno);
        }
    }
    | PLUS expression %prec UPLUS   {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = unaryOpResult(false, expr, yylineno);
        }
    }
    | INC expression %prec INC      {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = unaryOpResult(true, expr, yylineno);
        }
    }
    | DEC expression %prec DEC      {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = unaryOpResult(false, expr, yylineno);
        }
    }
    | expression INC %prec POSTINC {
        ExprInfo expr = *$1; delete $1;
        if (!expr.isValid) {
            $$ = makeInvalidExpr();
        } else {
            $$ = unaryOpResult(true, expr, yylineno); // true 表示 ++
        }
    }
    | expression DEC %prec POSTDEC {
        ExprInfo expr = *$1; delete $1;
        if (!expr.isValid) {
            $$ = makeInvalidExpr();
        } else {
            $$ = unaryOpResult(false, expr, yylineno); // false 表示 --
        }
    }
    | LPAREN expression RPAREN       { 
        if (!$2->isValid) {
            delete $2;
            $$ = makeInvalidExpr();
        }else{
            $$ = $2;
        }
    }
    | lvalue                         {
        Symbol* sym = $1;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        
        if (!exprPtr->isValid) {
            delete exprPtr;
            $$ = makeInvalidExpr();
        }else{
            $$ = exprPtr;
        }

        if(sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                } else if (sym->type->base == BK_Bool) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                }
            } else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Bool) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                }
            }
        }
    }
    | const_lit                      { 
        if (!$1->isValid) {
            delete $1;
            $$ = makeInvalidExpr();
        }else{
            $$ = $1;
        }
    }
    | func_call                      { 
        if (!$1->isValid) {
            delete $1;
            $$ = makeInvalidExpr();
        }else{
            $$ = $1;
        }
    }
    ;

/* Constants */
const_lit
    : INT_LIT     { 
        $$ = new ExprInfo(ctx->typePool.make(BK_Int), true);
        $$->setInt($1);
    }
    | REAL_LIT    {
        $$ = new ExprInfo(ctx->typePool.make(BK_Float), true);
        $$->setFloat($1);
    }
    | BOOL_LIT    {
        $$ = new ExprInfo(ctx->typePool.make(BK_Bool), true);
        $$->setBool($1);
    }    
    | STRING_LIT  { 
        $$ = new ExprInfo(ctx->typePool.make(BK_String), true);
        $$->setString(*$1);
        delete $1;
    }
    ;

/* Function Calls */
func_call
    : ID LPAREN arg_list_opt RPAREN {
        Symbol* symbol = ctx->symTab.lookup(*$1);
        std::string funcName = *$1; delete $1;
        std::vector<ExprInfo> args = *$3; delete $3;

        if (symbol != nullptr) {
            if (symbol->type->base == BK_Void) {
                SemanticError("function " + funcName + " should not return value", yylineno);
                $$ = makeInvalidExpr();
            }else{
                if (checkFuncCall(symbol, funcName, args, yylineno)){
                    $$ = new ExprInfo(symbol->type->ret);
                }else{
                    $$ = makeInvalidExpr();
                }
            }
        }else {
            SemanticError("undeclared function: " + funcName, yylineno);
            $$ = makeInvalidExpr();
        }
    }

proc_call
    : ID LPAREN arg_list_opt RPAREN {
        Symbol* symbol = ctx->symTab.lookup(*$1);
        std::string funcName = *$1; delete $1;
        std::vector<ExprInfo> args = *$3; delete $3;
        if (symbol != nullptr){
            checkFuncCall(symbol, funcName, args, yylineno);
            if (symbol->type->base != BK_Void) {
                SemanticError("function " + funcName + " should get return value", yylineno);
            }
        }else{
            SemanticError("undeclared function: " + funcName, yylineno);
        }
    }

/* Function Arguments */
arg_list_opt
    : /* empty */{ $$ = new std::vector<ExprInfo>();}
    | arg_list { $$ = $1; }
    ;

arg_list
    : expression {
        $$ = new std::vector<ExprInfo>();
        $$->push_back(*$1);
        delete $1;
    }
    | arg_list COMMA expression{
        $$ = $1;
        $$->push_back(*$3);
        delete $3;
    }
    ;

/* Type Specification */
type_spec
    : INT_TOK    { $$ = ctx->typePool.make(BK_Int); ctx->nowType = $$; }
    | FLOAT_TOK      { $$ = ctx->typePool.make(BK_Float); ctx->nowType = $$; }
    | BOOL_TOK       { $$ = ctx->typePool.make(BK_Bool);  ctx->nowType = $$; }
    | STRING_TOK { $$ = ctx->typePool.make(BK_String); ctx->nowType = $$;}
    ;

%% 

int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        std::puts("Usage: sd <source-file>");
        return 1;
    }

    // Try to open the input file
    if (!(yyin = std::fopen(argv[1], "r"))) {
        perror("open"); // Print system error message
        return 1;
    }

    std::filesystem::path p(argv[1]);
    std::string fileName = p.stem().string() + ".j";
    std::string baseName = p.stem().string();

    // Initialize semantic analysis context
    Context context;
    ctx = &context;

    ctx->fileContent.push_back("class " + baseName);
    ctx->fileContent.push_back("{");
    int result = yyparse();
    ctx->fileContent.push_back("}");

    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    for (const auto& line : ctx->fileContent) {
        outputFile << line << "\n";
    }

    outputFile.close();

    if (SemanticWarning::hasWarning()) {
        SemanticWarning::printAllWarning();
    }
    
    if (SemanticError::hasError()) {
        SemanticError::printAllError();
        result += 2;
    }

    if (SemanticError::hasError() || result != 0) {
        std::filesystem::remove(fileName.c_str()); // Remove the output file if there are errors
    }

    return result;
}