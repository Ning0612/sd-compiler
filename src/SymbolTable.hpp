#pragma once

#include "Symbol.hpp"
#include <string>
#include <vector>
#include <unordered_map>

/* ───────────── SymbolTable ─────────────
   Manages scopes and symbol declarations.
   Supports nested scopes (stack-based).
*/
class SymbolTable {
    using Bucket = std::unordered_map<std::string, Symbol>;
    std::vector<Bucket> scopes { Bucket() }; // scopes[0] = global scope
    int nextIndex = 0; // Global counter for non-constant symbols (excluding global scope)
    int currentFunctionIndex = 0; // Current function's local index counter

public:
    void enterScope();                          // push new scope
    void leaveScope();                          // pop current scope
    void enterFunction();                       // mark start of new function
    bool insert(const Symbol& s);               // insert symbol into current scope
    Symbol* lookup(const std::string& name);    // search from innermost to outermost
    Symbol* lookupGlobal(const std::string& name); // search global scope only
    void dbgPrintCurrentScope() const;
    int getCurrentScopeIndex() const { return scopes.size() - 1; }
};