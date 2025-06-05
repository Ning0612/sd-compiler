#include "SymbolTable.hpp"
#include <cstdio>
#include <algorithm>

/* ───────────── SymbolTable Methods ───────────── */

// Enter a new scope by pushing a new bucket onto the stack
void SymbolTable::enterScope() {
    scopes.emplace_back();
}

// Mark the start of a new function (reset function-local index)
void SymbolTable::enterFunction() {
    currentFunctionIndex = 0;
}

// Leave the current scope by popping the last bucket from the stack
void SymbolTable::leaveScope() {
    dbgPrintCurrentScope();
    scopes.pop_back();

    if (scopes.size() == 1) {
        currentFunctionIndex = 0;
    }
}

// Insert a symbol into the current scope
// Returns true if the symbol was successfully inserted, false if it already exists
// Assigns index to non-constant symbols in non-global scopes
bool SymbolTable::insert(const Symbol& s) {
    Symbol symbol = s; // Create a copy to modify
    
    // Assign index only for non-constant symbols and non-global scope
    if (!symbol.isConst && scopes.size() > 1) {
        symbol.index = currentFunctionIndex++;
        nextIndex++; // Still increment global counter for uniqueness
    } else {
        symbol.index = -1; // Constants and global symbols get -1
    }
    
    return scopes.back().insert({symbol.name, symbol}).second;
}

// Lookup a symbol by name, searching from the innermost to the outermost scope
// Returns a pointer to the symbol if found, or nullptr if not found
Symbol* SymbolTable::lookup(const std::string& n) {
    for (int i = scopes.size() - 1; i >= 0; --i) {
        auto it = scopes[i].find(n);
        if (it != scopes[i].end()) return &it->second;
    }
    return nullptr;
}

// Lookup a symbol in the global scope only
// Returns a pointer to the symbol if found, or nullptr if not found
Symbol* SymbolTable::lookupGlobal(const std::string& n) {
    auto it = scopes[0].find(n);
    return (it != scopes[0].end()) ? &it->second : nullptr;
}

// Debug print the current scope's symbols
// Prints the scope index and each symbol's details
void SymbolTable::dbgPrintCurrentScope() const {
    printf("\n======= Symbol Table in scope [%ld] =======\n", scopes.size() - 1);
    
    for (const auto& p : scopes.back()) {
        const Symbol& symbol = p.second;
        printf("ID: %s, Type: ", symbol.name.c_str());
        symbol.type->dbgPrint();
        
        // Print index for non-constant symbols in non-global scope
        if (!symbol.isConst && scopes.size() > 1 && symbol.index >= 0) {
            printf(", Index: %d", symbol.index);
        }
        
        if (symbol.isConst) {
            printf(", Const");
            if (symbol.hasConstValue()) {
                printf(" = ");
                switch (symbol.valueKind) {
                    case VK_Int:    printf("%d", symbol.iVal); break;
                    case VK_Float:  printf("%f", symbol.fVal); break;
                    case VK_Bool:   printf("%s", symbol.bVal ? "true" : "false"); break;
                    case VK_String: printf("\"%s\"", symbol.sVal.c_str()); break;
                    default: break;
                }
            }
        }
        puts("");
    }
    printf("\n");
}