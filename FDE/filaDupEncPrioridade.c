#include <stdlib.h>
#include "arq.h"

Descritor* cria(int tam_max) {
    Descritor* fila = (Descritor*)malloc(sizeof(Descritor));
    fila->tam_max = tam_max; 
    fila->tam_atual = 0;
    fila->cauda = NULL;
    fila->frente = NULL;
    return fila;
} 

int cheia(Descritor* fila) {
    return fila->tam_atual == fila->tam_max;
}

int vazia(Descritor *fila) {
    return (fila->cauda == NULL && fila->frente == NULL);
}

int insereNaFila(Info* novo, Descritor* fila) {
    if ( cheia(fila) ) 
        return 0;
        
    Elemento* novo_nodo = (Elemento*)malloc(sizeof(Elemento));
    novo_nodo->dados = *novo;
    novo_nodo->prox = NULL;
    novo_nodo->ant = NULL; 

    if ( vazia(fila) ) {
        fila->frente = novo_nodo;
        fila->cauda = novo_nodo;
    } else if ( novo->idade > fila->frente->dados.idade ) {
        novo_nodo->ant = fila->frente;
        fila->frente->prox = novo_nodo;
        fila->frente = novo_nodo;
    } else if ( novo->idade <= fila->cauda->dados.idade ) {
        novo_nodo->prox = fila->cauda;
        fila->cauda->ant = novo_nodo;
        fila->cauda = novo_nodo;
    } else {
        Elemento* temp = fila->cauda;
        while ( novo->idade > temp->dados.idade )
            temp = temp->prox;
        novo_nodo->ant = temp->ant;
        novo_nodo->prox = temp;
        temp->ant = novo_nodo;
    }

    fila->tam_atual += 1;
    return 1;
}

int tamanhoDaFila(Descritor *fila) {
    return fila->tam_atual;
}

void reinicia(Descritor* fila){
    Elemento* temp1 = fila->cauda;
    Elemento* temp2 = fila->cauda->prox;
    int i;
    for(i = 0; i < tamanhoDaFila(fila); i++) {
        free(temp1);
        temp1 = temp2;
        temp2 = temp1->prox;
    }
    fila->tam_atual = 0;
}

void destroi(Descritor *fila) {
    reinicia(fila);
    free(fila);
}

int buscaNaCauda(Info* copia, Descritor *fila) {
    if ( vazia(fila) )
        return 0;
    *copia = fila->cauda->dados;
    return 1;
}

int buscaNaFrente(Info* copia, Descritor *fila) {
    if ( vazia(fila) )
        return 0;
    *copia = fila->frente->dados;
    return 1;
}

int retiraDaFila(Info* copia, Descritor* fila) { 
    if ( vazia(fila) )
        return 0;
    *copia = fila->frente->dados;
    Elemento* temp = fila->frente->ant;
    free(fila->frente);
    fila->frente = temp;
    fila->frente->prox = NULL;
    fila->tam_atual -= 1;
    return 1;
} 

int inverte(Descritor* fila) {
    if ( vazia(fila) )
        return 0;
    Elemento* aux1 = fila->cauda;
    Elemento* aux2;
    while( aux1 != NULL ) {
        aux2 = aux1->ant;
        aux1->ant = aux1->prox;
        aux1->prox = aux2;
        aux1 = aux1->ant;
    }
    aux1 = fila->cauda;
    fila->cauda = fila->frente;
    fila->frente = aux1;
    return 1;
}


