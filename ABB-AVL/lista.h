#ifndef LISTA
#define LISTA
#include <stdlib.h>

typedef struct Nodo_LDE {
    struct Nodo_LDE* proximo;
    struct Nodo_LDE* anterior;
    int linha;
} Nodo_LDE;

typedef struct {
    Nodo_LDE* inicio;
    int tamanho;
} Lista;

Lista* criar_LDE();
Lista* destruir_LDE();
void inserir_LDE(Lista* lista, int linha);
int remover_LDE(Lista* lista, int linha);

#endif