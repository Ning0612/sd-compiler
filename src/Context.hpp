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
    std::vector<std::string> pendingIfLabels;
    std::vector<std::string> pendingForeachId;                           // foreach 變數名
    std::vector<std::pair<std::string, std::string>> pendingWhileLabels;  // {begin, end}
    std::vector<std::tuple<std::string, std::string, std::string>> pendingForLabels;  // {update, condition, end}
    std::vector<size_t> pendingForUpdate;  // 用於插入更新代碼的位置
    int equalLabelCounter = 0;      // E標籤 (== !=)
    int compareLabelCounter = 0;    // C標籤 (> >= < <=)
    int forLabelCounter = 0;        // F標籤 (for loop)
    int ifLabelCounter = 0;         // I標籤 (if else)
    int whileLabelCounter = 0;      // W標籤 (while)
};