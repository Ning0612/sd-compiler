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
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""); break;
                case VK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"); break;
                case VK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(varInit.iVal ? "1" : "0")); break;
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
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""); break;
                case VK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"); break;
                case VK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(varInit.iVal ? "1" : "0")); break;
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
            declaration +=(paramList[i].type->base == BK_Int) ? "int" :
                           (paramList[i].type->base == BK_Float) ? "float" :
                           (paramList[i].type->base == BK_Bool) ? "int" :
                           (paramList[i].type->base == BK_String) ? "java.lang.String" : "unknown";
        }

        declaration += ")";

        ctx->fileContent.push_back(declaration);
        ctx->fileContent.push_back("    max_stack 31");
        ctx->fileContent.push_back("    max_locals 31");
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
                declaration += (paramList[i].type->base == BK_Int) ? "int" :
                               (paramList[i].type->base == BK_Float) ? "float" :
                               (paramList[i].type->base == BK_Bool) ? "int" :
                               (paramList[i].type->base == BK_String) ? "java.lang.String" : "unknown";
            }
            declaration += ")";

            ctx->fileContent.push_back(declaration);
        }
        
        ctx->fileContent.push_back("    max_stack 31");
        ctx->fileContent.push_back("    max_locals 31");
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

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->fileContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)"); break;
            case BK_Float: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)"); break;
            case BK_Bool: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)"); break;
            case BK_String: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
    | PRINTLN expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->fileContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)"); break;
            case BK_Float: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)"); break;
            case BK_Bool: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)"); break;
            case BK_String: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)"); break;
            default: break;
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
        if ($1 != nullptr) delete checkIncDecValid(true, false, $1, &ctx->fileContent, yylineno);
     }
    | lvalue DEC SEMICOLON {
        if ($1 != nullptr) delete checkIncDecValid(false, false, $1, &ctx->fileContent, yylineno);
     }
    | INC lvalue SEMICOLON {
        if ($2 != nullptr) delete checkIncDecValid(true, false, $2, &ctx->fileContent, yylineno);
     }
    | DEC lvalue SEMICOLON {
        if ($2 != nullptr) delete checkIncDecValid(false, false, $2, &ctx->fileContent, yylineno);
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
            if (value.isConst) {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string(value.iVal)); break;
                    case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string(value.fVal) + "f"); break;
                    case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string(value.bVal ? "1" : "0")); break;
                    case BK_String: ctx->fileContent.push_back("        ldc \"" + value.sVal + "\""); break;
                    default: break;
                }
            }

            if (sym->index == -1) {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        putstatic int " + sym->name); break;
                    case BK_Float: ctx->fileContent.push_back("        putstatic float " + sym->name); break;
                    case BK_Bool: ctx->fileContent.push_back("        putstatic int " + sym->name); break;
                    default: break;
                }
            } else {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        istore " + std::to_string(sym->index)); break;
                    case BK_Float: ctx->fileContent.push_back("        fstore " + std::to_string(sym->index)); break;
                    case BK_Bool: ctx->fileContent.push_back("        istore " + std::to_string(sym->index)); break;
                    default: break;                
                }
            }
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

if_prefix
    : IF LPAREN expression RPAREN
      {
          ExprInfo expr = *$3; delete $3;
          if (expr.isValid) checkBoolExpr("if", expr, yylineno);
          if (expr.isConst) emitConst(expr, ctx);

          /* 先預設 false-label */
          ctx->fileContent.push_back("        ifeq FFalse" + std::to_string(ctx->ifFalseLabelCounter));
          ctx->ifFalseLabels.push_back(ctx->ifFalseLabelCounter);
          ctx->ifFalseLabelCounter++;
      }
    ;

opt_else
    : ELSE
      {
        /* 這裡放你原本 $@4 的動作：從 then 區塊跳到 exit */
        ctx->fileContent.push_back("        goto FExit" + std::to_string(ctx->ifExitLabelCounter));
        ctx->ifExitLabels.push_back(ctx->ifExitLabelCounter);
        ctx->ifExitLabelCounter++;

        ctx->fileContent.push_back("FFalse" + std::to_string(ctx->ifFalseLabels.back()) + ":");
        ctx->ifFalseLabels.pop_back();
        ctx->fileContent.push_back("        nop");

      }
      statement                    /* else 區塊 */
      {
        ctx->fileContent.push_back("FExit" + std::to_string(ctx->ifExitLabels.back()) + ":");
        ctx->ifExitLabels.pop_back();
        ctx->fileContent.push_back("        nop");
      }
    | /* empty */                  /* 沒有 else */
      {
        ctx->fileContent.push_back("FFalse" + std::to_string(ctx->ifFalseLabels.back()) + ":");
        ctx->ifFalseLabels.pop_back();
        ctx->fileContent.push_back("        nop");
      }
    ;

if_stmt
    : if_prefix statement opt_else %prec IFX
    ;

/* Loop Statements */
loop_stmt
    : WHILE {
        ctx->fileContent.push_back("WBegin" + std::to_string(ctx->whileLabelCounter) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->whileLabels.push_back(ctx->whileLabelCounter);
        ctx->whileLabelCounter++;
    } LPAREN expression {
        ExprInfo expr = *$4; delete $4;
        if (expr.isValid) checkBoolExpr("while", expr, yylineno); 
        if (expr.isConst) emitConst(expr, ctx);
        ctx->fileContent.push_back("        ifeq WEnd" + std::to_string(ctx->whileLabels.back()));
    } RPAREN statement{ 
        ctx->fileContent.push_back("        goto WBegin" + std::to_string(ctx->whileLabels.back()));
        ctx->fileContent.push_back("WEnd" + std::to_string(ctx->whileLabels.back()) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->whileLabels.pop_back();
    }
    | DO {
        ctx->fileContent.push_back("DBegin" + std::to_string(ctx->whileLabelCounter) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->whileLabels.push_back(ctx->whileLabelCounter);
        ctx->whileLabelCounter++;
    } statement WHILE LPAREN expression RPAREN SEMICOLON {
        ExprInfo expr = *$6; delete $6;
        if (expr.isValid) checkBoolExpr("do while", expr, yylineno);
        if (expr.isConst) emitConst(expr, ctx);
        ctx->fileContent.push_back("        ifne DBegin" + std::to_string(ctx->whileLabels.back()));
        ctx->fileContent.push_back("DEnd" + std::to_string(ctx->whileLabels.back()) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->whileLabels.pop_back();
    }
    | FOR LPAREN for_simple_opt SEMICOLON {
        ctx->fileContent.insert(ctx->fileContent.end(), ctx->forOpContent.begin(), ctx->forOpContent.end());
        ctx->forOpContent.clear();
        ctx->fileContent.push_back("ForBegin" + std::to_string(ctx->forLabelCounter) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->forLabels.push_back(ctx->forLabelCounter);
        ctx->forLabelCounter++;
    } expression SEMICOLON{
        ExprInfo expr = *$6; delete $6;
        if (expr.isValid) checkBoolExpr("for", expr, yylineno);
        if (expr.isConst) emitConst(expr, ctx);
        ctx->fileContent.push_back("        ifeq ForEnd" + std::to_string(ctx->forLabels.back()));
    } for_simple_opt RPAREN statement{
        ctx->fileContent.insert(ctx->fileContent.end(), ctx->forOpContent.begin(), ctx->forOpContent.end());
        ctx->forOpContent.clear();
        ctx->fileContent.push_back("        goto ForBegin" + std::to_string(ctx->forLabels.back()));
        ctx->fileContent.push_back("ForEnd" + std::to_string(ctx->forLabels.back()) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->forLabels.pop_back();
    }
| FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN {
    ExprInfo from = *$5; ExprInfo to = *$8; delete $5; delete $8;
    std::string id = *$3; delete $3;
    if (from.isValid && to.isValid) {
        checkForeachRange(from, to, yylineno);
    }
    checkForeachIndex(ctx->symTab.lookup(id), yylineno);

    Symbol* sym = ctx->symTab.lookup(id);
    if (sym != nullptr) {
        tryDeclareVarable(ctx->symTab, VarInit("_to", ctx->typePool.make(BK_Int)), ctx->typePool.make(BK_Int), yylineno);
        tryDeclareVarable(ctx->symTab, VarInit("_delta", ctx->typePool.make(BK_Int)), ctx->typePool.make(BK_Int), yylineno);

        Symbol* toSym = ctx->symTab.lookup("_to");
        Symbol* deltaSym = ctx->symTab.lookup("_delta");

        // 1. 設定 _to 變數
        if (to.isConst) {
            switch (to.type->base) {
                case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string(to.iVal)); break;
                case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string(to.fVal) + "f"); break;
                case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string(to.bVal ? "1" : "0")); break;
                default: break;
            }
        }

        if (toSym->index != -1) {
            ctx->fileContent.push_back("        istore " + std::to_string(toSym->index));
        } else {
            ctx->fileContent.push_back("        putstatic int " + toSym->name);
        }

        // 2. 初始化迴圈變數 (id = from)
        if (from.isConst) {
            switch (from.type->base) {
                case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string(from.iVal)); break;
                case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string(from.fVal) + "f"); break;
                case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string(from.bVal ? "1" : "0")); break;
                default: break;
            }
        }

        if (sym->index != -1) {
            ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
        } else {
            ctx->fileContent.push_back("        putstatic int " + sym->name);
        }

        // 3. 計算 delta (from < to ? 1 : -1)
        // 載入 from 和 to 進行比較
        if (sym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + sym->name);
        }
        
        if (toSym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(toSym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + toSym->name);
        }

        ctx->fileContent.push_back("        isub");  // from - to
        ctx->fileContent.push_back("        iflt ForEachDelta" + std::to_string(ctx->foreachDeltaCounter));
        ctx->fileContent.push_back("        ldc -1");  // from >= to, delta = -1
        ctx->fileContent.push_back("        goto ForEachDelta" + std::to_string(ctx->foreachDeltaCounter + 1));
        ctx->fileContent.push_back("ForEachDelta" + std::to_string(ctx->foreachDeltaCounter) + ":");
        ctx->fileContent.push_back("        ldc 1");   // from < to, delta = 1
        ctx->fileContent.push_back("ForEachDelta" + std::to_string(ctx->foreachDeltaCounter + 1) + ":");
        ctx->fileContent.push_back("        nop");

        // 儲存 delta
        if (deltaSym->index != -1) {
            ctx->fileContent.push_back("        istore " + std::to_string(deltaSym->index));
        } else {
            ctx->fileContent.push_back("        putstatic int " + deltaSym->name);
        }

        // 4. 迴圈開始
        ctx->fileContent.push_back("ForEachBegin" + std::to_string(ctx->forLabelCounter) + ":");
        ctx->fileContent.push_back("        nop");
        ctx->forLabels.push_back(ctx->forLabelCounter);
        
        // 5. 迴圈條件檢查 - 使用 isub 和符號判斷
        // 先檢查 delta 的符號來決定比較方式
        if (deltaSym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(deltaSym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + deltaSym->name);
        }
        
        ctx->fileContent.push_back("        ifgt ForEachCheckDesc" + std::to_string(ctx->foreachDeltaCounter));
        
        // delta = 1 (遞增)：檢查 current - to，如果 > 0 則結束
        if (sym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + sym->name);
        }
        
        if (toSym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(toSym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + toSym->name);
        }
        
        ctx->fileContent.push_back("        isub");  // current - to
        ctx->fileContent.push_back("        iflt ForEachEnd" + std::to_string(ctx->forLabelCounter));
        ctx->fileContent.push_back("        goto ForEachStatement" + std::to_string(ctx->forLabelCounter));
        
        // delta = -1 (遞減)：檢查 current - to，如果 < 0 則結束
        ctx->fileContent.push_back("ForEachCheckDesc" + std::to_string(ctx->foreachDeltaCounter) + ":");
        
        if (sym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + sym->name);
        }
        
        if (toSym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(toSym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + toSym->name);
        }
        
        ctx->fileContent.push_back("        isub");  // current - to
        ctx->fileContent.push_back("        ifgt ForEachEnd" + std::to_string(ctx->forLabelCounter));

        ctx->fileContent.push_back("ForEachStatement" + std::to_string(ctx->forLabelCounter) + ":");
        ctx->fileContent.push_back("        nop");

        ctx->foreachDeltaCounter += 2;
        ctx->forLabelCounter++;
        ctx->forEachId.push_back(id);
    }
} statement {
    // 迴圈體執行完後，更新迴圈變數
    std::string loopId = ctx->forEachId.back();
    ctx->forEachId.pop_back();
    
    Symbol* sym = ctx->symTab.lookup(loopId);
    Symbol* deltaSym = ctx->symTab.lookup("_delta");
    
    if (sym && deltaSym) {
        // 載入當前值
        if (sym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + sym->name);
        }
        
        // 載入 delta
        if (deltaSym->index != -1) {
            ctx->fileContent.push_back("        iload " + std::to_string(deltaSym->index));
        } else {
            ctx->fileContent.push_back("        getstatic int " + deltaSym->name);
        }
        
        ctx->fileContent.push_back("        iadd");  // current + delta
        
        // 儲存更新後的值
        if (sym->index != -1) {
            ctx->fileContent.push_back("        istore " + std::to_string(sym->index));
        } else {
            ctx->fileContent.push_back("        putstatic int " + sym->name);
        }
    }
    
    // 跳回迴圈開始
    ctx->fileContent.push_back("        goto ForEachBegin" + std::to_string(ctx->forLabels.back()));
    ctx->fileContent.push_back("ForEachEnd" + std::to_string(ctx->forLabels.back()) + ":");
    ctx->fileContent.push_back("        nop");
    ctx->forLabels.pop_back();
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

        ctx->forOpContent.push_back("        getstatic java.io.PrintStream java.lang.System.out");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->forOpContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.print(int)"); break;
            case BK_Float: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.print(float)"); break;
            case BK_Bool: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)"); break;
            case BK_String: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
    | PRINTLN expression  {
        ExprInfo expr = *$2; delete $2;
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->forOpContent.push_back("        getstatic java.io.PrintStream java.lang.System.out");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->forOpContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.println(int)"); break;
            case BK_Float: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.println(float)"); break;
            case BK_Bool: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)"); break;
            case BK_String: ctx->forOpContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
    | READ lvalue  {
        Symbol* sym = $2;
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
    }
    | lvalue INC {
        if ($1 != nullptr)  delete checkIncDecValid(true, false, $1, &ctx->forOpContent, yylineno);
     }
    | lvalue DEC {
        if ($1 != nullptr)  delete checkIncDecValid(false, false, $1, &ctx->forOpContent, yylineno);
     }
    | INC lvalue {
        if ($2 != nullptr)  delete checkIncDecValid(true, false, $2, &ctx->forOpContent, yylineno);
     }
    | DEC lvalue {
        if ($2 != nullptr)  delete checkIncDecValid(false, false, $2, &ctx->forOpContent, yylineno);
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

            if (value.isConst) {
                switch (target.type->base) {
                    case BK_Int: ctx->forOpContent.push_back("        ldc " + std::to_string(value.iVal)); break;
                    case BK_Float: ctx->forOpContent.push_back("        ldc " + std::to_string(value.fVal) + "f"); break;
                    case BK_Bool: ctx->forOpContent.push_back("        ldc " + std::string(value.bVal ? "1" : "0")); break;
                    case BK_String: ctx->forOpContent.push_back("        ldc \"" + value.sVal + "\""); break;
                    default: break;
                }
            }

            if (sym->index == -1) {
                switch (target.type->base) {
                    case BK_Int: ctx->forOpContent.push_back("        putstatic int " + sym->name); break;
                    case BK_Float: ctx->forOpContent.push_back("        putstatic float " + sym->name); break;
                    case BK_Bool: ctx->forOpContent.push_back("        putstatic int " + sym->name); break;
                    default: break;
                }
            } else {
                switch (target.type->base) {
                    case BK_Int: ctx->forOpContent.push_back("        istore " + std::to_string(sym->index)); break;
                    case BK_Float: ctx->forOpContent.push_back("        fstore " + std::to_string(sym->index)); break;
                    case BK_Bool: ctx->forOpContent.push_back("        istore " + std::to_string(sym->index)); break;
                    default: break;                
                }
            }
        }
    }
    ;

/* Return Statement */
return_stmt
    : RETURN expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        ctx->returnsExpr.push_back(std::make_pair(expr, yylineno));

        if (expr.isConst) emitConst(expr, ctx);

        switch (ctx->funcType->base) {
            case BK_Int: ctx->fileContent.push_back("        ireturn"); break;
            case BK_Float: ctx->fileContent.push_back("        freturn"); break;
            case BK_Bool: ctx->fileContent.push_back("        ireturn"); break;
            default: SemanticError("unsupported return type", yylineno);
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
                $$ = numericOpResult(OPADD, lhs, rhs, ctx, yylineno);
            }
        }
    }
    | expression MINUS expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPSUB, lhs, rhs, ctx, yylineno);
        }
    }
    | expression MUL   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPMUL, lhs, rhs, ctx, yylineno);
        }
    }
    | expression DIV   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPDIV, lhs, rhs, ctx, yylineno);
        }
    }
    | expression MOD   expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = numericOpResult(OPMOD, lhs, rhs, ctx, yylineno);
        }
    }
    | expression LT    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPLT, lhs , rhs, ctx, yylineno);
        }
    }
    | expression LE    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPLE, lhs , rhs, ctx, yylineno);
        }
    }
    | expression GT    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPGT, lhs , rhs, ctx, yylineno);
        }
    }
    | expression GE    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = relOpResult(OPGE, lhs , rhs, ctx, yylineno);
        }
    }
    | expression EQ    expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = eqOpResult(true, lhs, rhs, ctx, yylineno);
        }
    }
    | expression NEQ   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = eqOpResult(false, lhs, rhs, ctx, yylineno);
        }
    }
    | expression AND   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = boolOpResult(true, lhs , rhs, ctx, yylineno);
        }   
    }
    | expression OR expression      {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = boolOpResult(false, lhs , rhs, ctx, yylineno);
        }
    }
    | NOT expression                {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = notOpResult(expr, ctx, yylineno);
        }
    }
    | MINUS expression %prec UMINUS {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = unaryOpResult(true, expr, ctx, yylineno);
        }
    }
    | PLUS expression %prec UPLUS   {
        ExprInfo expr = *$2; delete $2;
        if(!expr.isValid) {
            $$ = makeInvalidExpr();
        }
        else{
            $$ = unaryOpResult(false, expr, ctx, yylineno);
        }
    }
    | INC lvalue %prec INC      {
        $$ = checkIncDecValid(true, true, $2, &ctx->fileContent, yylineno);
     }
    | DEC lvalue %prec DEC      {
        $$ = checkIncDecValid(false, true, $2, &ctx->fileContent, yylineno);
     }
    | lvalue INC %prec POSTINC {
        $$ = checkIncDecValid(true, true, $1, &ctx->fileContent, yylineno);
     }
    | lvalue DEC %prec POSTDEC {
        $$ = checkIncDecValid(false, true, $1, &ctx->fileContent, yylineno);
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
            if (!sym->isConst){
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
                    std::string call = "        invokestatic ";
                    call += symbol->type->ret->base == BK_Void ? "void " : baseKindToJavaStr(symbol->type->ret->base) + " ";
                    call += funcName + "(";
                    for (size_t  i = 0; i < args.size(); ++i) {
                        if (i > 0) call += ", ";
                        switch (args[i].type->base) {
                            case BK_Int: call += "int"; break;
                            case BK_Float: call += "float"; break;
                            case BK_Bool: call += "int"; break;
                            default: SemanticError("unsupported argument type in function call", yylineno);
                        }
                    }
                    call += ")";
                    ctx->fileContent.push_back(call);

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
            }else{
                std::string call = "        invokestatic ";
                call += "void " + funcName + "(";
                for (size_t i = 0; i < args.size(); ++i) {
                    if (i > 0) call += ", ";
                    switch (args[i].type->base) {
                        case BK_Int: call += "int"; break;
                        case BK_Float: call += "float"; break;
                        case BK_Bool: call += "int"; break;
                        default: SemanticError("unsupported argument type in function call", yylineno);
                    }
                }
                call += ")";
                ctx->fileContent.push_back(call);
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
        if ($1->isConst) {
            switch ($1->type->base) {
                case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string($1->iVal)); break;
                case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string($1->fVal) + "f"); break;
                case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string($1->bVal ? "1" : "0")); break;
                case BK_String: ctx->fileContent.push_back("        ldc \"" + $1->sVal + "\""); break;
                default: break;
            }
        }

        $$ = new std::vector<ExprInfo>();
        $$->push_back(*$1);
        delete $1;
    }
    | arg_list COMMA expression{
        if ($3->isConst) {
            switch ($3->type->base) {
                case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string($3->iVal)); break;
                case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string($3->fVal) + "f"); break;
                case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string($3->bVal ? "1" : "0")); break;
                case BK_String: ctx->fileContent.push_back("        ldc \"" + $3->sVal + "\""); break;
                default: break;
            }
        }

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