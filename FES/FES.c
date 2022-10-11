
#include <stdlib.h>

typedef struct {
    int* dados;
    int frente;
    int cauda;
    int tam;
    int tam_max;
} FES;

FES* cria(int tam) {
    FES* fila = (FES*)malloc(sizeof(FES));
    fila->dados = (int*)malloc(sizeof(int) * tam);
    fila->tam_max = tam;
    fila->tam = 0;
    fila->frente = 0;
    fila->cauda = -1;
    return fila;
}

int vazia(FES* fila) {
    return fila->frente > fila->cauda;
}

int cheia(FES* fila) {
    return fila->cauda == fila->tam_max - 1;
}

int insere(FES* fila, int info) {
    if ( cheia(fila) )
        return 0;
    fila->cauda++;
    fila->dados[fila->cauda] = info;
    fila->tam++;
    return 1;
}

int remove(FES* fila) {
    if ( vazia(fila) )
        return 0;
    fila->frente++;
    fila->tam--;
}

int tamanho(FES* fila) {
    return fila->tam;
}

int* busca_frente(FES* fila) {
    if ( vazia(fila) )
        return NULL;
    int copia = fila->dados[fila->frente];
    return &copia;
}

int* busca_cauda(FES* fila) {
    if ( vazia(fila) )
        return NULL;
    int copia = fila->dados[fila->cauda];
    return &copia;
}



