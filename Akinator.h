//
// Created by avbol on 02.12.2018.
//

#ifndef FIRST_CLION_AKINATOR_H
#define FIRST_CLION_AKINATOR_H

#include "Tree.h"

#define INPUT_FILE "output.txt"

class Akinator
{
public:
    Tree* base_tree;

    Akinator();
    Akinator(Tree* tree);

    void Run();
    void Search(Node* node);
    void AddWord(Node* node);
};

#endif //FIRST_CLION_AKINATOR_H
