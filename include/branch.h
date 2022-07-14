#pragma once
#include <iostream>

class Branch {
    int childCount = 0;
    Branch* parent = nullptr;
    Branch* child = nullptr;
    std::string name = "none";

public:
    Branch* getTopBranch();
    void setChild(Branch* inChild);
};