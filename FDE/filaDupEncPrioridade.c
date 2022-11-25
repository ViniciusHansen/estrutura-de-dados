#include <stdlib.h>
#include "arq.h"

Descritor* cria(int tam_max) {
    Descritor* fila = (Descritor*)malloc(sizeof(Descritor));
    fila->tam_max = tam_max; 
    fila->tam_atual = 0;
    fila->cauda = NULL;
    fila->frente = NULL;
    fila->ref_movel = NULL;
    return fila;
} 

int cheia(Descritor* fila) {
    return fila->tam_atual == fila->tam_max;
}

int vazia(Descritor *fila) {
    return (fila->cauda == NULL && fila->frente == NULL && fila->ref_movel == NULL);
}

int insereNaFila(Info* novo, Descritor* fila) {
    if ( cheia(fila) ) 
        return 0;    

    Elemento* novo_nodo = (Elemento*)malloc(sizeof(Elemento));
    Elemento* temp;
    novo_nodo->dados = *novo;
    novo_nodo->prox = NULL;
    novo_nodo->ant = NULL;

    if ( vazia(fila) ) {
        fila->frente = novo_nodo;
        fila->cauda = novo_nodo;
        fila->ref_movel = novo_nodo;
        fila->tam_atual += 1;
        return 1;
    }

    int dist_frente = abs(fila->frente->dados.idade - novo->idade);
    int dist_cauda = abs(fila->cauda->dados.idade - novo->idade);
    int dist_ref_movel = abs(fila->ref_movel->dados.idade - novo->idade);

    if ( novo->idade > fila->frente->dados.idade ) {
        novo_nodo->ant = fila->frente;
        fila->frente->prox = novo_nodo;
        fila->frente = novo_nodo;
    } else if ( novo->idade <= fila->cauda->dados.idade ) {
        novo_nodo->prox = fila->cauda;
        fila->cauda->ant = novo_nodo;
        fila->cauda = novo_nodo;
    } else if ( dist_cauda <= dist_frente && dist_cauda <= dist_ref_movel ) {
        temp = fila->cauda;
        while ( novo->idade > temp->dados.idade )
            temp = temp->prox;
        novo_nodo->ant = temp->ant;
        novo_nodo->prox = temp;
        temp->ant->prox = novo_nodo;
        temp->ant = novo_nodo;
    } else if ( dist_cauda <= dist_frente && dist_ref_movel < dist_cauda ) {
        temp =  fila->ref_movel;
        while ( novo->idade <= temp->dados.idade )
            temp = temp->ant;
        novo_nodo->ant = temp;
        temp->prox->ant = novo_nodo;
        novo_nodo->prox = temp->prox;
        temp->prox = novo_nodo;
    } else if ( dist_frente < dist_cauda && dist_frente < dist_ref_movel ) {
        temp = fila->frente;
        while ( novo->idade <= temp->dados.idade )
            temp = temp->ant;
        novo_nodo->ant = temp;
        temp->prox->ant = novo_nodo;
        novo_nodo->prox = temp->prox;
        temp->prox = novo_nodo;
    } else if ( dist_frente < dist_cauda && dist_ref_movel < dist_frente ) {
        temp = fila->ref_movel;
        while ( novo->idade > temp->dados.idade )
            temp = temp->prox;
        novo_nodo->ant = temp->ant;
        novo_nodo->prox = temp;
        temp->ant->prox = novo_nodo;
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
    Elemento* temp2;
    while( temp1 != NULL ) {
        temp2 = temp1->prox;
        free(temp1);
        temp1 = temp2;
        fila->tam_atual -= 1;
    }
    fila->frente = NULL;
    fila->cauda = NULL;
    fila->ref_movel = NULL;
}

void destroi(Descritor *fila) {
    reinicia(fila);
    free(fila);
}

int buscaNaCauda(Info* copia, Descritor *fila) {
    if ( vazia(fila) )
        return 0;
    *copia = fila->cauda->dados;
    fila->ref_movel = fila->cauda;
    return 1;
}

int buscaNaFrente(Info* copia, Descritor *fila) {
    if ( vazia(fila) )
        return 0;
    *copia = fila->frente->dados;
    fila->ref_movel = fila->frente;
    return 1;
}

int buscaNoRefMovel(Info* copia, Descritor *fila) {
    if ( vazia(fila) )
        return 0;
    *copia = fila->ref_movel->dados;
    return 1;
}

int retiraDaFila(Info* copia, Descritor* fila) { 
    if ( vazia(fila) )
        return 0;
    *copia = fila->frente->dados;
    Elemento* temp = fila->frente->ant;
    free(fila->frente);
    fila->frente = temp;
    fila->ref_movel = fila->frente;
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


