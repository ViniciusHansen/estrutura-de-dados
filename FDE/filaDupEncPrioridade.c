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

int insereNaFila(Elemento* novo, Descritor* fila, int (*compara)(Elemento e1, Elemento* e2)) {
    int dist_cauda = abs(fila->cauda->prioridade - novo->prioridade);
    int dist_frente = abs(fila->frente->prioridade - novo->prioridade);
    int dist_ref_movel = abs(fila->ref_movel->prioridade - novo->prioridade);
    if ( )
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

int retiraDaFila(Elemento* elem, Descritor* fila) { //Retirar a primeira ocorrência?
    if ( vazia(fila) )
        return 0;
    int dist_cauda = abs(fila->cauda->prioridade - elem->prioridade);
    int dist_frente = abs(fila->frente->prioridade - elem->prioridade);
    int dist_ref_movel = abs(fila->ref_movel->prioridade - elem->prioridade);
    Elemento* temp;
    if ( dist_cauda < dist_frente && dist_cauda < dist_ref_movel ) {
        temp = fila->cauda;
        while( temp != fila->ref_movel ) {
            
        }
    }
} 

int* buscaNoRefMovelFrente(Elemento *elem, Descritor *fila) { //Não sabemos como fazer
    if ( vazia(fila) )
        return NULL;
    Elemento* temp = fila->ref_movel;
    for( i = )
}