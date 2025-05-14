// VarInit.cpp
#include "VarInit.hpp"

// Constructor for variable without type (used for basic declaration)
VarInit::VarInit(std::string n)
    : name(n), constType(nullptr), isValid(true) {}

// Constructor for variable with specified type
VarInit::VarInit(std::string n, Type* t)
    : name(n), constType(t), isValid(true) {}


VarInit* makeInvalidVar() {
    VarInit* inValid = new VarInit("", nullptr);
    inValid->isValid = false;
    inValid->constType = nullptr;
    return inValid;
}