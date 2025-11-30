#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    FILE *f = fopen("../arvore.txt", "r");
    Node *root = NULL;

    if (f) {
        root = load_tree(f);
        fclose(f);
    } else {
        printf("Criando árvore inicial...\n");
        root = create_node("É uma pessoa?");
        root->yes = create_node("Sherlock Holmes");
        root->no = create_node("Scooby-Doo");
    }

    int opcao;
    do {
        printf("\n=== Detective Quest ===\n");
        printf("1 - Jogar\n");
        printf("2 - Mostrar árvore\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) play(root);
        if (opcao == 2) print_tree(root, 0);

    } while (opcao != 0);

    f = fopen("../arvore.txt", "w");
    save_tree(root, f);
    fclose(f);

    free_tree(root);

    return 0;
}
