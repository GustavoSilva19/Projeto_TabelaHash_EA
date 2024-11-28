#ifndef TABELA_HASH_H
#define TABELA_HASH_H

// Definimos o tamanho fixo da tabela hash.
#define TAMANHO_TABELA 1000

// Estrutura que armazena as informações de cada mangá.
// Inclui um código único (chave), título e autor.
typedef struct {
    int codigo;           
    char titulo[100];    
    char autor[100];      
} Manga;

// Estrutura que define cada elemento da tabela hash.
// Inclui o mangá e um indicador se a posição está ocupada ou não.
typedef struct {
    Manga manga;          // Dados do mangá
    int ocupado;          // 0 = Livre, 1 = Ocupado
} ElementoHash;

// Declaração das funções que manipulam a tabela hash.
void inicializar_tabela();              // Inicializa a tabela hash (define todas as posições como livres)
int funcao_hash(int chave);             // Calcula o índice da tabela baseado na chave
void inserir(int codigo, const char *titulo, const char *autor); // Insere um mangá na tabela
Manga* buscar(int codigo);              // Busca um mangá na tabela
void remover(int codigo);               // Remove um mangá da tabela
void imprimir_tabela();                 // Imprime os elementos da tabela

#endif
