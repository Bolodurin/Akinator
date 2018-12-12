//
// Created by avbol on 25.11.2018.
//

#ifndef FIRST_CLION_TREE_H
#define FIRST_CLION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <assert.h>

#define OUTPUT_FILE "output.txt"
#define OUTPUT1_FILE "output1.txt"
#define OUTPUT_DOT_FILE "output1.dot"

typedef struct Node
{
    Node* parent;
    char*data;
    Node* left;
    Node* right;

    bool VerificationNode();

    Node(char*data_node, Node* par, Node* lft, Node* rght);
    Node(Node* node);
    ~Node();

    void PrintNodeInFile(FILE *output);
    Node* ReadNodeFromFile(FILE* input, Node* parent);
}Node;

class Tree
{
public:
    Node* root;
    int quantity_nodes;

    Tree();
    ~Tree();

    explicit Tree(char* root_el);
    Tree(Tree* tree);

    bool VerificationTree();

    void PrintLikeGraph();
    void PrintInFile();
    Tree* ReadFromFile();

private:
    void RecursPrint(FILE *output, Node *node);
};

#endif //FIRST_CLION_TREE_H
