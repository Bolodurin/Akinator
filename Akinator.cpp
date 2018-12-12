//
// Created by avbol on 02.12.2018.
//

#include "Akinator.h"

Akinator::Akinator() {
    base_tree = base_tree->ReadFromFile();
}

Akinator::Akinator(Tree *tree) {
    assert(tree);
    assert(tree->VerificationTree());

    base_tree = new Tree(tree);
    assert(base_tree->VerificationTree());
}

void Akinator::Run() {
    printf("Hello in Akinator\n");
    if(base_tree->VerificationTree())
        Search(base_tree->root);
}

void Akinator::Search(Node* node) {
    assert(node);
    printf("%s?[y/n]\n", node->data);
    //printf("1:wht\n");
    char answer[1] = "";
    scanf("%s", answer);

    if(answer[0] == 'y' || answer[0] == 'Y')
    {
        if (node->left)   Search(node->left);
        else
        {
            printf("I knew.\n");
            printf("Do you want replay?\n");
            scanf("%s", answer);
            if(answer[0] == 'y' || answer[0] == 'Y')
                Search(base_tree->root);
            else if(answer[0] == 'n' || answer[0] == 'N')
            {
                printf("Goodbye!\n");
                return;
            }
            else
            {
                printf("Sorry, I don't like errors1\n");
                return;
            }
        }
    }
    else if(answer[0] == 'n' || answer[0] == 'N')
    {
        if (node->right)   Search(node->right);
        else
        {
            AddWord(node);
            Search(base_tree->root);
        }
    }
    else
    {
        printf("Sorry, I don't like errors2\n");
        return;
    }
}

void Akinator::AddWord(Node *node) {
    assert(node);
    //printf("%s\n", node->parent->right->data);

    printf("But what is it?\n");
    char answer[100] = "";
    scanf(" %[^\n]", answer);
    if(strlen(answer) == 0)
    {
        printf("ERROR with answer\n");
        assert(nullptr);
    }

    printf("Where difference with %s(what is true for my answer?)?\n", node->data);
    char difference[100] = "";
    scanf(" %[^\n]", difference);
    if(strlen(difference) == 0)
    {
        printf("ERROR with difference\n");
        assert(nullptr);
    }

    Node* diff_node = new Node(difference, node->parent, node, nullptr);
    assert(diff_node);
    Node* new_node = new Node(answer, diff_node, nullptr, nullptr);
    assert(answer);

    if(node == node->parent->left)
    {
        node->parent->left = diff_node;
        node->parent = diff_node;
        diff_node->right = new_node;
        base_tree->quantity_nodes += 2;
    }
    else if(node == node->parent->right)
    {
        node->parent->right = diff_node;
        node->parent = diff_node;
        diff_node->right = new_node;
        base_tree->quantity_nodes += 2;
    }
    else
    {
        printf("ERROR with node in AddWord");
        assert(nullptr);
    }
}