#include <iostream>
#include <string>
#include <cmath>

class Branch {
    int childCount = 0;
    Branch* parent = nullptr;
    Branch* child = nullptr;
    std::string name = "none";

public:
    Branch* getTopBranch() {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return nullptr;
        return parent->getTopBranch();
    }
    void setChild(Branch* inChild) {
        if (child == nullptr) {
            child = inChild;
            childCount++;
        }
        else {
            *(&child + 1) = inChild;
            childCount++;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
