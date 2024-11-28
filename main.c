#include <stdio.h>
#include "tabela_hash.h"

// Função principal para interação com o sistema de mangás.
int main() {
    inicializar_tabela(); // Inicializa a tabela hash

    int opcao, codigo;
    char titulo[100], autor[100];

    do {
        // Menu para o usuário escolher a operação
        printf("\n1. Inserir Manga\n2. Buscar Manga\n3. Remover Manga\n4. Imprimir Tabela\n5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Inserir
                printf("Digite o codigo do manga: ");
                scanf("%d", &codigo);

                // Limpando o buffer de entrada
                while ((getchar()) != '\n'); 

                printf("Digite o titulo do manga: ");
                scanf(" %[^\n]s", titulo);
                printf("Digite o autor do manga: ");
                scanf(" %[^\n]s", autor);
                inserir(codigo, titulo, autor);
                break;
            case 2: // Buscar
                printf("Digite o codigo do manga que quer buscar: ");
                scanf("%d", &codigo);
                Manga *resultado = buscar(codigo);
                if (resultado) {
                    printf("Manga encontrado -> Codigo: %d, Titulo: %s, Autor: %s\n", 
                            resultado->codigo, resultado->titulo, resultado->autor);
                } else {
                    printf("Manga nao encontrado.\n");
                }
                break;
            case 3: // Remover
                printf("Digite o codigo do manga que quer remover: ");
                scanf("%d", &codigo);
                remover(codigo);
                break;
            case 4: // Imprimir
                imprimir_tabela();
                break;
            case 5: // Sair
                printf("Saindo\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
