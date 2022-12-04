#ifndef LISTA
#define LISTA
#include <stdlib.h>

typedef struct Nodo_LDE {
    Nodo_LDE* proximo;
    Nodo_LDE* anterior;
    int linha;
} Nodo_LDE;

typedef struct {
    Nodo_LDE* inicio;
    int tamanho;
} Lista;

Lista* criar_lista();
Lista* destruir_lista();
void lista_inserir(Lista* lista, int linha);
int lista_remover(Lista* lista, int linha);

#endif