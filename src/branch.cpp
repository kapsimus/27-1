#include <cmath>
#include "branch.h"


int Branch::randomTo(int number){
    return std::rand() % number;
}

Branch* Branch::getTopBranch() {
    if (parent == nullptr) return nullptr;
    if (parent->parent == nullptr) return nullptr;
    return parent->getTopBranch();
}

void Branch::setChild(Branch* inChild) {
    if (child == nullptr) {
        child = inChild;
        childCount++;
    }
    else {
        *(&child + 1) = inChild;
        childCount++;
    }

Branch* Branch::createTree() {
        Branch* tree = nullptr;


    }
}
