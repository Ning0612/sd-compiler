// VarInit.cpp
#include "VarInit.hpp"

// Constructor for variable without type (used for basic declaration)
VarInit::VarInit(std::string n, Type* t) : name(n), constType(nullptr), isValid(true) {
    constType = t; // Set type to null if no specific type is provided
    switch (t->base) {
        case BK_Int:
            valueKind = VK_Int; // Integer type
            iVal = 0; // Default integer value
            break;
        case BK_Float:
            valueKind = VK_Float; // Float type
            fVal = 0.0f; // Default float value
            break;
        case BK_Bool:
            valueKind = VK_Int; // Boolean treated as integer
            iVal = 0; // Default boolean value (false)
            break;
        default:
            valueKind = VK_None; // No valid type
            break;
    }
}

// Constructor for variable with specified type
VarInit::VarInit(std::string n, ExprInfo e) : name(n), isValid(true) {
    constType = e.type;
    switch (constType->base) {
        case BK_Int:
            valueKind = VK_Int;
            iVal = e.getInt(); // Get integer value from expression
            break;
        case BK_Float:
            valueKind = VK_Float;
            fVal = e.getFloat(); // Get float value from expression
            break;
        case BK_Bool:
            valueKind = VK_Int;
            iVal = (e.getBool() ? 1 : 0); // Convert boolean to integer
            break;
        default:
            valueKind = VK_None; // No valid type
            break;
    }
}

VarInit* makeInvalidVar() {
    VarInit* inValid = new VarInit("", nullptr);
    inValid->isValid = false;
    inValid->constType = nullptr;
    return inValid;
}