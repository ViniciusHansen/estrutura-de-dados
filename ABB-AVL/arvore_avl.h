#ifndef ARVORE
#define ARVORE
#include "lista.h"
#include <stdlib.h>

typedef struct Nodo_ABB {
    Nodo_ABB* esquerda;
    Nodo_ABB* direita;
    Lista* ocorrencias;
    int altura;
    long chave;
} Nodo_ABB;

typedef struct {
    Nodo_ABB* raiz;
} Arvore;

Arvore* criar_arvore();
Arvore* destruir_arvore(Arvore* descritor);
Lista* arvore_buscar(Arvore* descritor, long chave, int linha);
void arvore_inserir(Arvore* descritor, long chave, int linha);

#endif