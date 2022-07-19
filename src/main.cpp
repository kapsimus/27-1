#include <iostream>
#include <string>
#include "branch.h"

#define NUM_OF_TREES 5

int main()
{
    std::string elfName;
    int count = -1;
    Branch* tree[NUM_OF_TREES];
    for (int i = 0; i < NUM_OF_TREES; i++) {
        tree[i] = new Branch();
        tree[i]->createTree();
        tree[i]->enterNames();
        tree[i]->writeNames();
    }
//    for (int i = 0; i < NUM_OF_TREES; i++) {
//        tree[i] = new Branch();
//        tree[i]->createTree();
//        tree[i]->createElves("Elf" + std::to_string(i), 0);
//        tree[i]->writeNames();
//    }
    std::cout << "Enter elf name: ";
    std::getline(std::cin, elfName);
    for (int i = 0; i < NUM_OF_TREES; i++) {
        count = tree[i]->findNeighbours(tree[i]->findElf(elfName));
        if (count != -1) {
            break;
        }
    }
    if (count == -1) {
        std::cout << "Elf by name " << elfName << " not found." << std::endl;
    } else {
        std::cout << "Elf " << elfName << " has " << count << " neighbors." << std::endl;
    }
    for (int i = 0; i < NUM_OF_TREES; i++) {
        delete tree[i];
    }
}
