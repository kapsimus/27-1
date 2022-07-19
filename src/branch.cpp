#include <cmath>
#include "branch.h"
#include <ctime>

//5 trees, 3-5 big branches, 2-3 average branches

int Branch::randomRange(int from, int to){
    if (from >= to) return 0;
    return from + std::rand() % (to - from + 1);
}

void Branch::setChild() {
    Branch* newChild = new Branch();
    newChild->parent = this;
    this->child.push_back(newChild);
    //std::cout << newChild << std::endl;
}

void Branch::createTree() {
    std::srand(time(nullptr));
    int numBigBranches = randomRange(3, 5);
    //std::cout << numBigBranches << std::endl;
    for (int i = 0; i < numBigBranches; i++) {
        //std::cout << "i=" << i << std::endl;
        this->setChild();
    }
    for (int i = 0; i < numBigBranches; i++) {
        int numAverageBranches = randomRange(2, 3);
        //std::cout << numAverageBranches << std::endl;
        for(int j = 0; j < numAverageBranches; j++) {
            //std::cout << "j=" << j << std::endl;
            this->child[i]->setChild();
        }
    }
}

Branch* Branch::findBigBranch() {
    if (this->parent != nullptr && this->parent->parent == nullptr) {
        return this;
    } else {
        return this->parent->findBigBranch();
    }
}

void Branch::createElves(const std::string& elfName, int index){
    std::string newName = elfName;
    int elfIndex = index;
    if (this->parent != nullptr && !this->child.empty()) {
        elfIndex *= 10;
        newName += (" Big" + std::to_string(elfIndex));
        this->name = newName;
    } else if (this->parent != nullptr && this->child.empty()) {
        elfIndex ++;
        newName += (" Average" + std::to_string(elfIndex));
        this->name = newName;
    }
    //std::cout << name << std::endl;
    if (!this->child.empty()) {
        for (Branch* c: this->child) {
            c->createElves(elfName, elfIndex);
            elfIndex++;
        }
    } else return;
}

Branch* Branch::findElf(const std::string& elfName) {
    Branch* out = nullptr;
    if (this->name == elfName) {
        return this;
    } else {
        if (!this->child.empty()) {
            for (Branch* c: this->child) {
                out = c->findElf(elfName);
                if (out != nullptr) {
                    return out;
                }
            }
        } else {
            return out;
        }
    }
    return out;
}

int Branch::findNeighbours(Branch* elfBranch){
    if (elfBranch == nullptr) {
        return -1;
    }
    Branch* root = elfBranch->findBigBranch();
    //std::cout << root->name << std::endl;
    int count = 0;
    if (root->name != "none") {
        count++;
    }
    for (Branch* c: root->child) {
        if (c->name != "none") {
            count++;
        }
    }
    return count - 1;
}

void Branch::enterNames() {
    if (this == nullptr) {
        return;
    }
    std::string elfName;
    int index = 0;
    for (Branch* c: this->child) {
        std::cout << "Enter the name of the elf living on the big branch number " << index << std::endl;
        std::getline(std::cin, elfName);
        if (elfName == "none" || elfName.length() == 0) {
            c->name = "none";
        } else {
            c->name = elfName;
        }
        index++;
    }
    index = 0;
    for (Branch* c: this->child) {
        for (Branch* b: c->child) {
            std::cout << "Enter the name of the elf living on the average branch number " << index << std::endl;
            std::getline(std::cin, elfName);
            if (elfName == "none" || elfName.length() == 0) {
                b->name = "none";
            } else {
                b->name = elfName;
            }
            index++;
        }
    }
}

void Branch::writeNames() {
    if (this == nullptr) {
        return;
    }
    for (Branch* c: this->child) {
        std::cout << c->name << std::endl;
        for (Branch* b: c->child) {
            std::cout << b->name << std::endl;
        }
    }

}

