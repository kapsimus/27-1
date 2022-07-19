#pragma once
#include <iostream>
#include <vector>

class Branch {
    Branch* parent = nullptr;
    std::vector<Branch*> child;
    std::string name = "none";
private:
    static int randomRange(int from, int to);
    void setChild();
    Branch* findBigBranch();

public:
    void createTree();
    void enterNames();
    void writeNames();
    void createElves(const std::string& elfName, int index);
    Branch* findElf(const std::string& elfName);
    int findNeighbours(Branch* elfBranch);
};