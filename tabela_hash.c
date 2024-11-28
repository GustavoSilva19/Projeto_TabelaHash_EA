#include <stdio.h>
#include <string.h>
#include "tabela_hash.h"

// Implementando a tabela hash como um array estático.
// Usamos "static" para limitar a visibilidade apenas para este arquivo.
static ElementoHash tabela[TAMANHO_TABELA];

// Inicializa todas as posições da tabela como livres.
void inicializar_tabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i].ocupado = 0; // Define a posição como não ocupada
    }
}

// Função hash simples baseada em módulo.
// Retorna o índice na tabela correspondente a chave.
// Escolhemos essa função por ser rápida e adequada para chaves numéricas.
int funcao_hash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Insere um mangá na tabela hash.
// Utiliza sondagem linear para tratar colisões.
void inserir(int codigo, const char *titulo, const char *autor) {
    int indice = funcao_hash(codigo); // Calcula o índice inicial
    int tentativas = 0;

    // Procura uma posição livre ou verifica duplicidade
    while (tabela[indice].ocupado && tentativas < TAMANHO_TABELA) {
        if (tabela[indice].manga.codigo == codigo) { // Verifica duplicata
            printf("Chave duplicada ;-;\n");
            return;
        }
        indice = (indice + 1) % TAMANHO_TABELA; // Sondagem linear
        tentativas++;
    }

    if (tentativas == TAMANHO_TABELA) { // Caso a tabela esteja cheia
        printf("Tabela cheia ;-;\n");
        return;
    }

    // Insere os dados na posição encontrada
    tabela[indice].manga.codigo = codigo;
    strcpy(tabela[indice].manga.titulo, titulo);
    strcpy(tabela[indice].manga.autor, autor);
    tabela[indice].ocupado = 1;
    printf("Manga inserido com sucesso!\n");
}

// Busca um mangá na tabela hash usando sua chave.
Manga* buscar(int codigo) {
    int indice = funcao_hash(codigo); // Calcula o índice inicial
    int tentativas = 0;

    // Percorre a tabela enquanto a posição estiver ocupada
    while (tabela[indice].ocupado && tentativas < TAMANHO_TABELA) {
        if (tabela[indice].manga.codigo == codigo) { // Verifica correspondência
            return &tabela[indice].manga; // Retorna o mangá encontrado
        }
        indice = (indice + 1) % TAMANHO_TABELA; // Sondagem linear
        tentativas++;
    }

    return NULL; // Retorna NULL se o mangá não for encontrado
}

// Remove um mangá da tabela hash.
void remover(int codigo) {
    int indice = funcao_hash(codigo); // Calcula o índice inicial
    int tentativas = 0;

    // Percorre a tabela até encontrar o elemento
    while (tabela[indice].ocupado && tentativas < TAMANHO_TABELA) {
        if (tabela[indice].manga.codigo == codigo) { // Verifica correspondência
            tabela[indice].ocupado = 0; // Marca a posição como livre
            printf("Manga removido com sucesso!\n");
            return;
        }
        indice = (indice + 1) % TAMANHO_TABELA; // Sondagem linear
        tentativas++;
    }

    printf("Manga nao encontrado ;-;\n");
}

// Imprime todos os elementos ocupados da tabela hash.
void imprimir_tabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela[i].ocupado) { // Verifica se a posição está ocupada
            printf("Indice %d -> Codigo: %d, Titulo: %s, Autor: %s\n", 
                    i, tabela[i].manga.codigo, tabela[i].manga.titulo, tabela[i].manga.autor);
        }
    }
}
