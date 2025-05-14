// VarInit.cpp
#pragma once

#include <string>
#include <vector>
#include "SdTypes.hpp"

// Represents a variable declaration, which may be a scalar or an array
struct VarInit {
    std::string name;             // Variable name
    Type* constType;              // Type of the variable (null if array dimensions are provided)
    bool isValid;

    // Constructor for an untyped variable (usually resolved later)
    VarInit(std::string n);

    // Constructor for a typed scalar variable
    VarInit(std::string n, Type* t);
};

VarInit* makeInvalidVar();
