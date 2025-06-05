// context.hpp
#pragma once
#include "SemanticAnalyzer.hpp"
#include "SdTypes.hpp"
#include <fstream>
#include <vector>

struct Context {
    SymbolTable symTab;
    TypeArena typePool;
    std::vector<std::pair<ExprInfo, int>> returnsExpr;
    Type* nowType = nullptr;
    std::vector<std::string> fileContent; // For storing file content
    Type* funcType = nullptr; // Type of the current function being processed
};