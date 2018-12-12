#include <iostream>
#include <stdio.h>
#include "Tree.h"
#include "Akinator.h"

int main()
{
    char word1[30] = "start";
    Tree* test_tree = new Tree(word1);
    char word2[30] = "left child";
    Node* lft = new Node(word2, test_tree->root, nullptr, nullptr);

    char word3[30] = "right child";
    Node* rght = new Node(word3, test_tree->root, nullptr, nullptr);

    char word4[30] = "leftright child";
    Node *lftrght = new Node(word4, lft, nullptr, nullptr);

    char word5[30] = "leftleft child";
    Node *lftlft = new Node(word5, lft, nullptr, nullptr);

    test_tree->root->left = lft;
    test_tree->root->right = rght;
    lft->right = lftrght;
    lft->left = lftlft;
    test_tree->quantity_nodes = 5;
    //test_tree->PrintInFile();

    Akinator* akinator1 = new Akinator();
    akinator1->base_tree->PrintInFile();

    Akinator* akinator = new Akinator(test_tree);

    //akinator->Run();
    //test_tree->PrintLikeGraph();
    //akinator->base_tree->PrintInFile();
    //test_tree->PrintInFile();

    return 0;
}
