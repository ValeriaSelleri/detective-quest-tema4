#ifndef TREE_H
#define TREE_H

#define MAX_TEXT 200

typedef struct Node {
    char text[MAX_TEXT];
    struct Node *yes;
    struct Node *no;
} Node;

Node* create_node(const char *text);
void free_tree(Node* root);
void play(Node *root);
void save_tree(Node *root, FILE *f);
Node* load_tree(FILE *f);
void print_tree(Node *root, int depth);

#endif
