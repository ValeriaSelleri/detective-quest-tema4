#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node* create_node(const char *text) {
    Node *n = (Node*)malloc(sizeof(Node));
    strcpy(n->text, text);
    n->yes = NULL;
    n->no = NULL;
    return n;
}

void free_tree(Node* root) {
    if (!root) return;
    free_tree(root->yes);
    free_tree(root->no);
    free(root);
}

void print_tree(Node *root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("- %s\n", root->text);
    print_tree(root->yes, depth + 1);
    print_tree(root->no, depth + 1);
}

void play(Node *root) {
    if (!root) return;

    if (root->yes == NULL && root->no == NULL) {
        printf("É isso? Você está pensando em: %s ? (s/n): ", root->text);
        char r;
        scanf(" %c", &r);
        if (r == 's' || r == 'S') {
            printf("Acertei!\n");
        } else {
            printf("Em quem você estava pensando? ");
            char novo[MAX_TEXT];
            getchar();
            fgets(novo, MAX_TEXT, stdin);
            novo[strcspn(novo, "\n")] = 0;

            printf("Me diga uma pergunta que diferencia %s de %s:\n> ", novo, root->text);
            char pergunta[MAX_TEXT];
            fgets(pergunta, MAX_TEXT, stdin);
            pergunta[strcspn(pergunta, "\n")] = 0;

            Node *antigo = create_node(root->text);
            Node *novon = create_node(novo);

            strcpy(root->text, pergunta);

            printf("Para %s a resposta é sim? (s/n): ", novo);
            char resp;
            scanf(" %c", &resp);

            if (resp == 's' || resp == 'S') {
                root->yes = novon;
                root->no = antigo;
            } else {
                root->yes = antigo;
                root->no = novon;
            }
        }
        return;
    }

    printf("%s (s/n): ", root->text);
    char r;
    scanf(" %c", &r);

    if (r == 's' || r == 'S')
        play(root->yes);
    else
        play(root->no);
}

void save_tree(Node *root, FILE *f) {
    if (!root) {
        fprintf(f, "#\n");
        return;
    }
    fprintf(f, "%s\n", root->text);
    save_tree(root->yes, f);
    save_tree(root->no, f);
}

Node* load_tree(FILE *f) {
    char line[MAX_TEXT];
    if (!fgets(line, MAX_TEXT, f)) return NULL;

    line[strcspn(line, "\n")] = 0;
    if (strcmp(line, "#") == 0) return NULL;

    Node *n = create_node(line);
    n->yes = load_tree(f);
    n->no = load_tree(f);
    return n;
}
