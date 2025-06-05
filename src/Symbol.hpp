#pragma once

#include "ExprInfo.hpp"
#include <string>
#include <vector>
#include <unordered_map>

/* ───────────── Symbol ─────────────
   Represents a declared symbol in the program:
   variable, constant, or function argument.
*/
class Symbol {
public:
    std::string name;      // symbol name
    Type* type;            // symbol type
    bool isConst;          // whether the symbol is constant
    int index;             // symbol index (-1 for constants or global scope)

    ValueKind valueKind = VK_None;  // constant value kind
    union {
        int iVal;
        float fVal;
        bool bVal;
    };
    std::string sVal; // string constants

    Symbol(const std::string& n, Type* t, bool c, int idx = -1);

    void setInt(int v);
    void setFloat(float v);
    void setBool(bool v);
    void setString(const std::string& s);
    bool hasConstValue() const;
    void setConstValueFromExpr(const ExprInfo* e);
    
    void setExprInfo(ExprInfo* expr);
    ExprInfo* getExprInfo() const;
    void dbgPrint() const;
};