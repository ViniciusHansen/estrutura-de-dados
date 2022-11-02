#include <stdlib.h>
#include "arq.h"


Descritor* cria(int tam_max) {
    Descritor* fila = (Descritor*)malloc(sizeof(Descritor*));
    fila->tam_max = tam_max; 
    fila->cauda = NULL;
    fila->frente = NULL;
    fila->ref_movel == NULL;
    return fila;
} 

int insereNaFila(Elemento* novo, Descritor* fila) {
    if ( vazia(fila) ) {
        fila->frente = novo;
        fila->cauda = novo;
        fila->ref_movel = novo;
        fila->tam_atual += 1;
        return 1;
    } else if ( cheia(fila) ) 
        return 0;
    
    int dist_cauda = abs(fila->cauda->prioridade - novo->prioridade);
    int dist_frente = abs(fila->frente->prioridade - novo->prioridade);
    int dist_ref_movel = abs(fila->ref_movel->prioridade - novo->prioridade);
    int entre_cauda_refmov = fila->cauda->prioridade >= novo->prioridade && fila->ref_movel <= novo->prioridade;
    Elemento* temp;
    if ( entre_cauda_refmov ) {
        temp = fila->cauda;
        while( novo->prioridade > temp->prioridade ) 
            temp = temp->prox;
    } else {
        temp = fila->frente;
        while( novo->prioridade <= temp->prioridade )
            temp = temp->ant;
    }
    novo->ant = temp->ant;
    novo->prox = temp;
    temp->ant = novo;
    fila->tam_atual += 1;
    return 1;
}

int tamanhoDaFila(Descritor *fila) {
    return fila->tam_atual;
}

int vazia(Descritor *fila){
    return (fila->cauda == NULL && fila->frente == NULL && fila->ref_movel == NULL);
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

void destroi(Descritor *fila){ //Aterrar ponteiro?
    reinicia(fila);
    free(fila);
}

int* buscaNaCauda(Elemento *elem, Descritor *fila){
    if ( vazia(fila) )
        return NULL;
    Elemento* temp = fila->cauda;
    int i = 0;
    for(i = 0; i < tamanhoDaFila(fila); i++) {
        if ( temp->valor == elem->valor ) //Comparação está certa?
            return &i;
        temp = temp->prox;
    }
    return NULL;
}

int* buscaNaFrente(Elemento *elem, Descritor *fila) {
    if ( vazia(fila) )
        return NULL;
    Elemento* temp = fila->frente;
    int i = 0;
    for(i = tamanhoDaFila(fila) - 1; i >= 0; i--) {
        if ( temp->valor == elem->valor ) //Comparação está certa?
            return &i;
        temp = temp->ant;
    }
    return NULL;
}

Elemento* retiraDaFila(Descritor* fila) { 
    if ( vazia(fila) )
        return NULL;
    Elemento* temp = fila->frente;
    fila->frente = fila->frente->ant;
    fila->tam_atual -= 1;
    return temp;
} 

int* buscaNoRefMovelFrente(Elemento *elem, Descritor *fila) { //Não sabemos como fazer
    if ( vazia(fila) )
        return NULL;
    Elemento* temp = fila->ref_movel;
}

int cheia(Descritor* fila) {
    return fila->tam_atual == fila->tam_max;
}