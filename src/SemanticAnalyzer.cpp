#include "SemanticAnalyzer.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

// convert ExprInfo to basic types
int toInt(const ExprInfo e){
    return (e.valueKind==VK_Int)? e.getInt() : (e.valueKind==VK_Float)? static_cast<int>(e.getFloat()) : 0;
}
float toFloat(const ExprInfo e){
    return (e.valueKind==VK_Float)? e.getFloat() : (e.valueKind==VK_Int)? e.getInt() : 0.0f;
}

bool toBool(const ExprInfo e){
    return (e.valueKind==VK_Bool)? e.getBool() : (e.valueKind==VK_Int)? e.getInt() : (e.valueKind==VK_Float)? static_cast<int>(e.getFloat()) : false;
}
std::string toString(const ExprInfo e){
    return (e.valueKind==VK_String)? e.getString() : (e.valueKind==VK_Int)? std::to_string(e.getInt()) : (e.valueKind==VK_Float)? std::to_string(e.getFloat()) : "";
}

void emitConst(const ExprInfo& e, Context* ctx) {
    switch (e.type->base) {
        case BK_Int:   ctx->fileContent.push_back("        ldc " + std::to_string(e.getInt()));         break;
        case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string(e.getFloat()) + "f"); break;
        case BK_Bool:  ctx->fileContent.push_back("        ldc " + std::to_string(e.getBool() ? 1 : 0));break;
        case BK_String: ctx->fileContent.push_back("        ldc \"" + e.getString() + "\""); break;
        default: break;
    }
}

/*───────── Type Compatibility ─────────*/
std::string numOpToStr(NumOp op) {
    switch (op) {
        case OPADD: return " + ";
        case OPSUB: return " - ";
        case OPMUL: return " * ";
        case OPDIV: return " / ";
        case OPMOD: return " % ";
        default: return "unknown";
    }
}

std::string relOpToStr(RelOp op) {
    switch (op) {
        case OPLT: return " < ";
        case OPLE: return " <= ";
        case OPGT: return " > ";
        case OPGE: return " >= ";
        default: return "unknown";
    }
}

/*───────── String Concatenation ─────────*/
ExprInfo* concatStringResult(const ExprInfo& lhs, const ExprInfo& rhs, TypeArena& pool, int lineno) {
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }
    
    if(!lhs.type->isScalar()){
        SemanticError("left operand must be string scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be string scalar", lineno);
        return makeInvalidExpr();
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_String), lhs.isConst && rhs.isConst);

    if (result->isConst) {
        result->setString(lhs.getString() + rhs.getString());
    }
    return result;
}

/*───────── numeric (+ - * / %) ─────────*/
ExprInfo* numericOpResult(NumOp op, const ExprInfo& lhs, const ExprInfo& rhs, Context* ctx, int lineno){
    TypeArena& pool = ctx->typePool;
    BaseKind b1=lhs.type->base, b2=rhs.type->base;
    if(!lhs.isValid || !rhs.isValid){
        return makeInvalidExpr();
    }

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("numeric type mismatch " + baseKindToStr(b1) + numOpToStr(op) + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    if((op==OPDIV||op==OPMOD) && rhs.isZeroValue()){
        if (op==OPDIV) {
            SemanticError("division by zero", lineno);
            return makeInvalidExpr();
        } else {
            SemanticError("modulus by zero", lineno);
            return makeInvalidExpr();
        }
    }

    BaseKind resultBase = promote(b1, b2);
    bool isConst = lhs.isConst && rhs.isConst;
    ExprInfo* result = new ExprInfo(pool.make(resultBase), isConst);

    if (isConvertible(b1, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b1) + " to " + baseKindToStr(resultBase), lineno);
    }
    if (isConvertible(b2, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b2) + " to " + baseKindToStr(resultBase), lineno);
    }

    if(isConst){
        if(resultBase==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            float r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                      (op==OPMUL)?a*b : (op==OPDIV)?a/b : std::fmod(a, b);
            result->setFloat(r);
        }else if(resultBase==BK_Int){
            int a=lhs.getInt(), b=rhs.getInt();
            int r = (op==OPADD)?a+b : (op==OPSUB)?a-b :
                    (op==OPMUL)?a*b : (op==OPDIV)?a/b : a%b;
            result->setInt(r);
        }
    }else{
        if (lhs.isConst){
            switch (b1) {
                case BK_Int:    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getInt())); break;
                case BK_Float:  ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getFloat()) + "f"); break;
                default: break; // no other types
            }
            ctx->fileContent.push_back("        swap");
        }

        if (rhs.isConst){
            switch (b2) {
                case BK_Int:    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getInt())); break;
                case BK_Float:  ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getFloat()) + "f"); break;
                default: break; // no other types
            }
        }

        switch (resultBase) {
            case BK_Int:
                switch (op) {
                    case OPADD: ctx->fileContent.push_back("        iadd"); break;
                    case OPSUB: ctx->fileContent.push_back("        isub"); break;
                    case OPMUL: ctx->fileContent.push_back("        imul"); break;
                    case OPDIV: ctx->fileContent.push_back("        idiv"); break;
                    case OPMOD: ctx->fileContent.push_back("        irem"); break;

                }
                break;

            case BK_Float:
                switch (op) {
                    case OPADD: ctx->fileContent.push_back("        fadd"); break;
                    case OPSUB: ctx->fileContent.push_back("        fsub"); break;
                    case OPMUL: ctx->fileContent.push_back("        fmul"); break;
                    case OPDIV: ctx->fileContent.push_back("        fdiv"); break;
                    case OPMOD: ctx->fileContent.push_back("        fmod"); break; 
                }
                break;
            default:
                return makeInvalidExpr();
        }
    }

    return result;
}

/*───────── relational (< <= > >=) ─────────*/
ExprInfo* relOpResult(RelOp op, const ExprInfo& lhs, const ExprInfo& rhs, Context* ctx, int lineno) {
    TypeArena& pool = ctx->typePool;
    BaseKind b1=lhs.type->base, b2=rhs.type->base;
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("relational type mismatch " + baseKindToStr(b1) + relOpToStr(op) + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    BaseKind resultBase = promote(b1, b2);
    bool isConst = lhs.isConst && rhs.isConst;
    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), isConst);

    if (isConvertible(b1, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b1) + " to " + baseKindToStr(resultBase), lineno);
    }
    if (isConvertible(b2, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b2) + " to " + baseKindToStr(resultBase), lineno);
    }

    if(isConst){
        if(resultBase==BK_Float){
            float a=toFloat(lhs), b=toFloat(rhs);
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            result->setBool(r);
        }else if(resultBase==BK_Int){
            int a=lhs.getInt(), b=rhs.getInt();
            bool r = (op==OPLT)?a<b:(op==OPLE)?a<=b:(op==OPGT)?a>b:a>=b;
            result->setBool(r);
        }
    } else {
        // 生成Java assembly代碼
        if (lhs.isConst) {
            // 處理左運算元是常數的情況
            switch(b1) {
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getBool() ? 1 : 0));
                    break;
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getInt()));
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getFloat()));
                    break;
                default: break;
            }
            ctx->fileContent.push_back("        swap");
        }

        if (rhs.isConst) {
            // 處理右運算元是常數的情況
            switch(b2) {
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getBool() ? 1 : 0));
                    break;
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getInt()));
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getFloat()));
                    break;
                default: break;
            }
        }

        // 生成比較指令序列，使用 C 前綴標籤 (Compare operations)
        std::string labelTrue = "C" + std::to_string(ctx->compareLabelCounter++);
        std::string labelEnd = "C" + std::to_string(ctx->compareLabelCounter++);

        // 根據數據類型選擇比較方式
        if (resultBase == BK_Float) {
            // 浮點數比較需要使用 fcmpl/fcmpg
            ctx->fileContent.push_back("        fcmpl");  // 或者根據需要使用 fcmpg
            
            // 現在棧頂是比較結果 (-1, 0, 1)，可以使用整數條件跳躍
            std::string jumpInstruction;
            switch(op) {
                case OPLT:  // 
                    jumpInstruction = "iflt";  // 結果 < 0
                    break;
                case OPLE:  // <=
                    jumpInstruction = "ifle";  // 結果 <= 0
                    break;
                case OPGT:  // >
                    jumpInstruction = "ifgt";  // 結果 > 0
                    break;
                case OPGE:  // >=
                    jumpInstruction = "ifge";  // 結果 >= 0
                    break;
            }
            
            ctx->fileContent.push_back("        " + jumpInstruction + " " + labelTrue);
        } else {
            // 整數比較使用減法
            ctx->fileContent.push_back("        isub");
            
            std::string jumpInstruction;
            switch(op) {
                case OPLT:  jumpInstruction = "iflt"; break;
                case OPLE:  jumpInstruction = "ifle"; break;
                case OPGT:  jumpInstruction = "ifgt"; break;
                case OPGE:  jumpInstruction = "ifge"; break;
            }
            
            ctx->fileContent.push_back("        " + jumpInstruction + " " + labelTrue);
        }

        ctx->fileContent.push_back("        iconst_0");  // false
        ctx->fileContent.push_back("        goto " + labelEnd);
        ctx->fileContent.push_back(labelTrue + ":");
        ctx->fileContent.push_back("        iconst_1");  // true
        ctx->fileContent.push_back(labelEnd + ":");
    }

    return result;
}

/*───────── equal / not‑equal ─────────*/
ExprInfo* eqOpResult(bool equal, const ExprInfo& lhs, const ExprInfo& rhs, Context* ctx, int lineno) {
    TypeArena& pool = ctx->typePool;
    BaseKind b1=lhs.type->base, b2=rhs.type->base;
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }

    if(!lhs.type->isScalar()){
        SemanticError("left operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!rhs.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return makeInvalidExpr();
    }

    if(!(isBaseCompatible(b1, b2))){
        SemanticError("equal type mismatch " + baseKindToStr(b1) + (equal?"==":"!=") + baseKindToStr(b2), lineno);
        return makeInvalidExpr();
    }

    bool isConst = lhs.isConst && rhs.isConst;
    BaseKind resultBase = promote(b1, b2);
    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), isConst);
    
    if (isConvertible(b1, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b1) + " to " + baseKindToStr(resultBase), lineno);
    }
    if (isConvertible(b2, resultBase)){
        SemanticWarning("implicit conversion from " + baseKindToStr(b2) + " to " + baseKindToStr(resultBase), lineno);
    }
    auto cmp=[&](auto a,auto b){return equal? a==b : a!=b;};

    if(isConst){
        switch(resultBase){
            case BK_Bool:   result->setBool(cmp(lhs.getBool(),   rhs.getBool())); break;
            case BK_String: result->setBool(cmp(lhs.getString(), rhs.getString())); break;
            case BK_Int:    result->setBool(cmp(lhs.getInt(),    rhs.getInt())); break;
            case BK_Float:  result->setBool(cmp(lhs.getFloat(),  rhs.getFloat())); break;
            default:        break;
        }
    } else {
        // 生成Java assembly代碼
        if (lhs.isConst) {
            // 處理左運算元是常數的情況
            switch(b1) {
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getBool() ? 1 : 0));
                    break;
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getInt()));
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getFloat()));
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + lhs.getString() + "\"");
                    break;
                default: break;
            }
            ctx->fileContent.push_back("        swap");
        }

        if (rhs.isConst) {
            // 處理右運算元是常數的情況
            switch(b2) {
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getBool() ? 1 : 0));
                    break;
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getInt()));
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getFloat()));
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + rhs.getString() + "\"");
                    break;
                default: break;
            }
        }

        // 生成比較指令序列，使用 E 前綴標籤 (Equal operations)
        std::string labelTrue = "E" + std::to_string(ctx->equalLabelCounter++);
        std::string labelEnd = "E" + std::to_string(ctx->equalLabelCounter++);
        
        // 根據數據類型選擇比較方式
        if (resultBase == BK_String) {
            // 字串比較使用 String.equals()
            ctx->fileContent.push_back("        invokevirtual boolean java.lang.String.equals(java.lang.Object)");
            if (!equal) {
                // 對於 != 需要反轉結果
                ctx->fileContent.push_back("        ifeq " + labelTrue);
                ctx->fileContent.push_back("        iconst_0");
                ctx->fileContent.push_back("        goto " + labelEnd);
                ctx->fileContent.push_back(labelTrue + ":");
                ctx->fileContent.push_back("        iconst_1");
                ctx->fileContent.push_back(labelEnd + ":");
            }
        } else if (resultBase == BK_Float) {
            // 浮點數比較使用 fcmpl
            ctx->fileContent.push_back("        fcmpl");
            
            if (equal) {
                // == : 結果為 0 時為真
                ctx->fileContent.push_back("        ifeq " + labelTrue);
            } else {
                // != : 結果不為 0 時為真
                ctx->fileContent.push_back("        ifne " + labelTrue);
            }
            
            ctx->fileContent.push_back("        iconst_0");  // false
            ctx->fileContent.push_back("        goto " + labelEnd);
            ctx->fileContent.push_back(labelTrue + ":");
            ctx->fileContent.push_back("        iconst_1");  // true
            ctx->fileContent.push_back(labelEnd + ":");
        } else {
            // 整數和布林比較使用減法
            ctx->fileContent.push_back("        isub");
            
            if (equal) {
                // == : 結果為 0 時為真
                ctx->fileContent.push_back("        ifeq " + labelTrue);
            } else {
                // != : 結果不為 0 時為真
                ctx->fileContent.push_back("        ifne " + labelTrue);
            }
            
            ctx->fileContent.push_back("        iconst_0");  // false
            ctx->fileContent.push_back("        goto " + labelEnd);
            ctx->fileContent.push_back(labelTrue + ":");
            ctx->fileContent.push_back("        iconst_1");  // true
            ctx->fileContent.push_back(labelEnd + ":");
        }
    }

    return result;
}

/*───────── and / or ─────────*/
ExprInfo* boolOpResult(bool isAnd, const ExprInfo& lhs, const ExprInfo& rhs, Context* ctx, int lineno) {
    TypeArena& pool = ctx->typePool;
    if (!lhs.isValid || !rhs.isValid) {
        return makeInvalidExpr();
    }

    if (!lhs.type->isScalar() || lhs.type->base != BK_Bool) {
        SemanticError("left operand must be bool scalar", lineno);
        return makeInvalidExpr();
    }

    if (!rhs.type->isScalar() || rhs.type->base != BK_Bool) {
        SemanticError("right operand must be bool scalar", lineno);
        return makeInvalidExpr();
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), lhs.isConst && rhs.isConst);
    if (result->isConst) {
        result->setBool(isAnd ? (lhs.getBool() && rhs.getBool()): (lhs.getBool() || rhs.getBool()));
    }else{
        if (lhs.isConst) {
            ctx->fileContent.push_back("        ldc " + std::to_string(lhs.getBool() ? 1 : 0));
            ctx->fileContent.push_back("        swap");
        }

        if (rhs.isConst) {
            ctx->fileContent.push_back("        ldc " + std::to_string(rhs.getBool() ? 1 : 0));
        }

        if (isAnd) {
            ctx->fileContent.push_back("        iand");
        } else {
            ctx->fileContent.push_back("        ior");
        }
    }

    return result;
}

/*───────── not ─────────*/
ExprInfo* notOpResult(const ExprInfo& expr, Context* ctx, int lineno) {
    TypeArena& pool = ctx->typePool;
    if (!expr.isValid) {
        return makeInvalidExpr();
    }

    if (!expr.type->isScalar() || expr.type->base != BK_Bool) {
        SemanticError("operand must be bool scalar", lineno);
        return makeInvalidExpr();
    }

    ExprInfo* result = new ExprInfo(pool.make(BK_Bool), expr.isConst);
    if (expr.isConst){
        result->setBool(!expr.getBool());
    } else {
        ctx->fileContent.push_back("        ldc 1");
        ctx->fileContent.push_back("        ixor"); // XOR with 1 flips the boolean value
    }

    return result;
}

/*───────── unary + / - ─────────*/
ExprInfo* unaryOpResult(bool isMinus, const ExprInfo& expr, Context* ctx, int lineno) {
    if (!expr.isValid) {
        return makeInvalidExpr();
    }

    if (!expr.type->isScalar()){
        SemanticError("unary op on non-scalar type", lineno);
        return makeInvalidExpr();
    }

    if (expr.type->base != BK_Int && expr.type->base != BK_Float){
        SemanticError("unary op on non-numeric type", lineno);
        return makeInvalidExpr();
    }

    ExprInfo* result = new ExprInfo(expr.type, expr.isConst);
    if (expr.isConst) {
        switch (expr.valueKind) {
            case VK_Int:
                result->setInt(isMinus ? -expr.getInt() : expr.getInt());
                break;
            case VK_Float:
                result->setFloat(isMinus ? -expr.getFloat() : expr.getFloat());
                break;
            default:
                SemanticError("unsupported unary constant type", lineno);
                return makeInvalidExpr();
        }
    }else{
        if (isMinus){
            switch (expr.type->base) {
                case BK_Int: ctx->fileContent.push_back("        ineg"); break;
                case BK_Float: ctx->fileContent.push_back("        fneg"); break;
                default: break; // no other types
            }
        }
    }
    return result;
}

/*───────── check is the expression a INC or DEC ─────────*/
// true for increment, false for decrement
ExprInfo *checkIncDecValid(const bool& op, const bool& relood, Symbol* sym, std::vector<std::string>* fileContent, int lineno) {
    ExprInfo *exprPtr = ((sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr());
    ExprInfo expr = *exprPtr; delete exprPtr;
    std::string opStr = (op ? "++" : "--");

    if (!expr.isValid) {
        return makeInvalidExpr();
    }

    if (expr.isConst){
        SemanticError(op + " cannot be applied to const", lineno);
        return makeInvalidExpr();
    }

    if (!expr.type->isScalar()){
        SemanticError(op + " cannot be applied to non-scalar type", lineno);
        return makeInvalidExpr();
    }

    if (expr.type->base != BK_Int && expr.type->base != BK_Float){
        SemanticError(op + " requires int/float, got: " + baseKindToStr(expr.type->base), lineno);
        return makeInvalidExpr();
    }

    if (sym != nullptr) {
        if (sym->index == -1) {
            if (sym->type->base == BK_Int) {
                fileContent->push_back("        getstatic int " + sym->name);
                fileContent->push_back("        ldc 1");
                fileContent->push_back((op ? "        iadd" : "        isub"));
                fileContent->push_back("        putstatic int " + sym->name);
                if (relood) fileContent->push_back("        getstatic int " + sym->name);

            } else if (sym->type->base == BK_Float) {
                fileContent->push_back("        getstatic float " + sym->name);
                fileContent->push_back("        ldc 1.0f");
                fileContent->push_back((op ? "        fadd" : "        fsub"));
                fileContent->push_back("        putstatic float " + sym->name);
                if (relood) fileContent->push_back("        getstatic float " + sym->name);
            }
        }
        else {
            if (sym->type->base == BK_Int) {
                fileContent->push_back("        iload " + std::to_string(sym->index));
                fileContent->push_back("        ldc 1");
                fileContent->push_back((op ? "        iadd" : "        isub"));
                fileContent->push_back("        istore " + std::to_string(sym->index));
                if (relood) fileContent->push_back("        iload " + std::to_string(sym->index));

            } else if (sym->type->base == BK_Float) {
                fileContent->push_back("        fload " + std::to_string(sym->index));
                fileContent->push_back("        ldc 1.0f");
                fileContent->push_back((op ? "        fadd" : "        fsub"));
                fileContent->push_back("        fstore " + std::to_string(sym->index));
                if (relood) fileContent->push_back("        fload " + std::to_string(sym->index));
            }
        }

        return  sym->getExprInfo();
    }
    return makeInvalidExpr();
}

/*───────── check is the expression a bool scalar ─────────*/
void checkBoolExpr(const std::string& context, const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return;
    }

    if (expr.type->base != BK_Bool || !expr.type->isScalar()) {
        SemanticError(context + " condition must be bool scalar", lineno);
        return;
    }
}

/*───────── check foreach range ─────────*/
void checkForeachRange(const ExprInfo& from, const ExprInfo& to, int lineno) {
    if (!from.isValid || !to.isValid) {
        return;
    }

    if (from.type->base != BK_Int || !from.type->isScalar())
        SemanticError("foreach range start must be const int scalar", lineno);

    if (to.type->base != BK_Int || !to.type->isScalar())
        SemanticError("foreach range end must be const int scalar", lineno);
}

/*───────── check foreach index ─────────*/
void checkForeachIndex(Symbol* sym, int lineno) {
    if (!sym){
        SemanticError("undeclared foreach variable", lineno);
        return;
    }

    if (sym->type->base != BK_Int){
        SemanticError("foreach index must be int", lineno);
        return;
    }

    if (sym->isConst){
        SemanticError("foreach index cannot be const", lineno);
        return;
    }
}

/*───────── check variable declaration ─────────*/
void tryInsertVar(SymbolTable& symTab, const Symbol& s, int lineno) {
    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        SemanticError("variable '" + s.name + "' conflicts with function", lineno);
        return;
    }

    if (!symTab.insert(s)) {
        SemanticError("redeclared variable: " + s.name, lineno);
        return;
    }
}

/*───────── check function declaration ─────────*/
void declareFunction(const std::string& name, Type* returnType, const std::vector<Symbol>& paramSyms, TypeArena& typePool, SymbolTable& symTab, int lineno) {
    std::vector<Type*> paramTypes;
    for (auto& param : paramSyms) {
        paramTypes.push_back(param.type);
    }

    Symbol* exist = symTab.lookupGlobal(name);
    if (exist) {
        SemanticError(" '" + name + "' already declared", lineno);
    } else {
        Type* funcType = typePool.makeFunc(returnType, paramTypes);
        Symbol funcSym(name, funcType, false);

        if (!symTab.insert(funcSym)) {
            SemanticError("redeclared func: " + name, lineno);
            return;
        }
    }

    symTab.enterScope();

    
    for (auto& param : paramSyms) {
        if (!symTab.insert(param)) {
            SemanticError("redeclared param: " + param.name, lineno);
            return;
        }
    }
}

/*───────── check function call ─────────*/
bool checkFuncCall(Symbol* symbol, const std::string& name, const std::vector<ExprInfo>& args, int lineno) {
    if (!symbol) {
        SemanticError("undeclared function: " + name, lineno);
        return false;
    }

    if (!symbol->type->isFunc()) {
        SemanticError("not a function: " + name, lineno);
        return false;
    }

    size_t argCount = args.size();
    size_t expected = symbol->type->params.size();

    if (argCount != expected) {
        SemanticError("function '" + name + "' expects " +
            std::to_string(expected) + " arguments, but got " +
            std::to_string(argCount), lineno);
        return false;
    }

    if (!args.empty()) {
        for (size_t i = 0; i < argCount; ++i) {
            const ExprInfo& arg = args.at(i);
            if (!arg.isValid) {
                return false;
            }

            if (!arg.type->isCompatibleWith(*symbol->type->params[i])) {
                SemanticError("argument type mismatch", lineno);
                return false;
            }

            if (isConvertible(arg.type->base, symbol->type->params[i]->base)) {
                SemanticWarning("implicit conversion from " + baseKindToStr(arg.type->base) + " to " + baseKindToStr(symbol->type->params[i]->base), lineno);
            }
        }
    }

    return true;
}

/*───────── check assignment ─────────*/
void checkAssignment(const ExprInfo& target, const ExprInfo& value, int lineno) {
    if (!target.isValid || !value.isValid) {
        return;
    }

    if (!target.type->isScalar()) {
        SemanticError("left operand must be scalar", lineno);
        return;
    }

    if (target.isConst) {
        SemanticError("cannot assign to const variable", lineno);
        return;
    }

    if (value.type->isFunc()) {
        SemanticError("cannot assign function to variable", lineno);
        return;
    }
    
    if(!value.type->isScalar()){
        SemanticError("right operand must be scalar", lineno);
        return;
    }

    if (isConvertible(value.type->base, target.type->base)) {
        SemanticWarning("implicit conversion from " + baseKindToStr(value.type->base) + " to " + baseKindToStr(target.type->base), lineno); 
    }else if(value.type->base != target.type->base){
        SemanticError("assignment type mismatch " + baseKindToStr(target.type->base) + " = " + baseKindToStr(value.type->base), lineno);
    }
}

/*───────── check print ─────────*/
void checkPrint(const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return;
    }

    if (!expr.type->isScalar()) {
        SemanticError("print only supports scalar type", lineno);
        return;
    }

    if (expr.type->base == BK_Void) {
        SemanticError("cannot print void type", lineno);
        return;
    }
}

/*───────── check read ─────────*/
void checkRead(const ExprInfo& expr, int lineno) {
    if (!expr.isValid) {
        return;
    }

    if (!expr.type->isScalar()) {
        SemanticError("read only supports scalar type", lineno);
        return;
    }

    if (expr.type->base == BK_Void) {
        SemanticError("cannot read to void type", lineno);
        return;
    }
}

/*───────── check variable declaration ─────────*/
void tryDeclareVarable(SymbolTable& symTab, const VarInit& varInit, Type* type, int lineno){
    if (!varInit.isValid) {
        return;
    }

    Symbol s("", nullptr, false);

    if (varInit.constType != nullptr) {
        if (!type->isCompatibleWith(*varInit.constType)) {
            SemanticError("var type mismatch", lineno);
            return;
        }

        if(isConvertible(type->base, varInit.constType->base)) {
            SemanticWarning("implicit conversion from " + baseKindToStr(varInit.constType->base) + " to " + baseKindToStr(type->base), lineno);
        }
        s = Symbol(varInit.name, type, false);
    }
    else {
        s = Symbol(varInit.name, type, false);
    }

    tryInsertVar(symTab, s, lineno);
    
}

/*───────── check constant declaration ─────────*/
void tryDeclareConstant(SymbolTable& symTab, std::string& id, Type* type, const ExprInfo& value, int lineno){
    if (!value.isValid) {
        return;
    }

    if (!type->isScalar()) {
        SemanticError("const type must be scalar", lineno);
        return;
    }

    if (!isBaseCompatible(type->base, value.type->base)) {
        SemanticError("const type mismatch " + baseKindToStr(type->base) + " = " + baseKindToStr(value.type->base), lineno);
        return;
    }

    if (!value.isConst) {
        SemanticError("const expression must be const", lineno);
        return;
    }

    Symbol s(id, type, true);
    s.setConstValueFromExpr(&value);

    Symbol* exist = symTab.lookupGlobal(s.name);
    if (exist && exist->type->isFunc()) {
        SemanticError("const '" + s.name + "' conflicts with function", lineno);
        return;
    }

    if (!symTab.insert(s)) {
        SemanticError("redeclared const: " + id, lineno);
        return;
    }

    if (isConvertible(type->base, value.type->base)) {
        SemanticWarning("implicit conversion from " + baseKindToStr(value.type->base) + " to " + baseKindToStr(type->base), lineno);
    }
}