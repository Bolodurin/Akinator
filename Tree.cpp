//
// Created by avbol on 25.11.2018.
//


#include "Tree.h"

bool Tree::VerificationTree() {
    return root->VerificationNode();
}

bool Node::VerificationNode(){
    return data &&
        (this->left ? this->left->VerificationNode() : true) &&
        (this->right ? this->right->VerificationNode() : true);
};

Tree::Tree() {
    quantity_nodes = 0;
    root = nullptr;
}

Node::Node(char* data_node, Node* par = nullptr,
        Node* lft = nullptr, Node* rght = nullptr) {
    if(!data_node)
    {
        printf("ERROR with creating node\n");
        assert(nullptr);
    }

    this->data = strdup(data_node);
    this->parent = par;
    this->left = lft;
    this->right = rght;
}

Node::Node(Node* node)
{
    this->data = strdup(node->data);

    if(node->left)
    {
        this->left = new Node(node->left);
        this->left->parent = this;
    }
    if(node->right)
    {
        this->right = new Node(node->right);
        this->right->parent = this;
    }
}

Node::~Node() {
    if(this->left)   delete(this->left);
    if(this->right)  delete(this->right);

    free(this->data);
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

Tree::Tree(char* root_el) {
    root = new Node(root_el);
    this->quantity_nodes = 1;
}

Tree::~Tree() {
    delete(this->root);
    this->quantity_nodes = 0;
}

void Node::PrintNodeInFile(FILE *output) {
    static int indent = 0;

    fprintf(output,
            "%*s{ %s\n",
            indent*4, "", this->data);

    indent++;
    if(this->left)
        this->left->PrintNodeInFile(output);
    else
        fprintf(output, "%*s{ }\n", indent*4,"");

    if(this->right)
        this->right->PrintNodeInFile(output);
    else
        fprintf(output, "%*s{ }\n", indent*4,"");
    indent--;

    fprintf(output, "%*s}\n", indent*4, "");
}

void Tree::PrintInFile() {
    FILE* output = fopen(OUTPUT1_FILE, "w");
    assert(output);

    if (VerificationTree())  root->PrintNodeInFile(output);
    else                     printf("ERROR with tree in PrintInFile");

    fclose(output);
}

void Tree::PrintLikeGraph() {
    if(!VerificationTree())
    {
        printf("ERROR in tree!\n");
    }

    FILE* output = fopen(OUTPUT_DOT_FILE, "w");
    assert(output);

    fprintf(output, "digraph BST {\n");
    fprintf(output, "    node [fontname=\"Arial\"];\n");

    if(!root)    fprintf(output, "\n");
    else         RecursPrint(output, root);

    fprintf(output, "}");
}

void Tree::RecursPrint(FILE* output, Node* node) {
    static int nullcount = 0;

    if(node->left)
    {
        fprintf(output, "    %s->%s;\n",
                node->data, node->left->data);
        RecursPrint(output, node->left);
    }
    else
    {
        fprintf(output, "    null%d [shape=point];\n", nullcount);
        fprintf(output, "    %s->null%d;\n", node->data, nullcount);
        nullcount++;
    }

    if(node->right)
    {
        fprintf(output, "    %s->%s;\n",
                node->data, node->right->data);
        RecursPrint(output, node->right);
    }
    else
    {
        fprintf(output, "    null%d [shape=point];\n", nullcount);
        fprintf(output, "    %s->null%d;\n", node->data, nullcount);
        nullcount++;
    }
}

Tree::Tree(Tree *tree):
    quantity_nodes(tree->quantity_nodes){
    root = new Node(tree->root);
}

Node* Node::ReadNodeFromFile(FILE* input, Node* parent = nullptr) {
    assert(input);
    Node* node;

    char new_buf[100] = "";
    fscanf(input, "%*2c%[^}\n]", new_buf);
    if(strlen(new_buf) == 0)
    {
        fscanf(input, "%*[^{]");
        return nullptr;
    }
    else    node = new Node(new_buf);
    assert(node);

    node->left = ReadNodeFromFile(input, node);
    node->right = ReadNodeFromFile(input, node);
    node->parent = parent;

    fscanf(input, "%*[^{]");
    return node;
}

Tree* Tree::ReadFromFile() {
    FILE* input = fopen(OUTPUT_FILE, "r");
    assert(input);

    Tree* tree = new Tree();
    tree->root = tree->root->ReadNodeFromFile(input);
    assert(tree->VerificationTree());

    fclose(input);
    return tree;
}




