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
    std::vector<int> ifFalseLabels; // Labels for if-else false branches
    std::vector<int> ifExitLabels;  // Labels for if-else exit points
    std::vector<int> forLabels;      // Labels for for loops
    std::vector<int> whileLabels;    // Labels for while loops
    std::vector<int> doWhileLabels;  // Labels for do-while loops

    int equalLabelCounter = 0;      // E標籤 (== !=)
    int compareLabelCounter = 0;    // C標籤 (> >= < <=)
    int ifFalseLabelCounter = 0;    // IFFalse標籤 (if else)
    int ifExitLabelCounter = 0;     // IExit標籤 (if else exit)
    int forLabelCounter = 0;        // F標籤 (for loop)
    int foreachLabelCounter = 0; // FEach標籤 (foreach loop)
    int whileLabelCounter = 0;      // W標籤 (while)
    int doWhileLabelCounter = 0;    // D標籤 (do-while)

    bool inIfStatement;
    bool ifHasElse;
};