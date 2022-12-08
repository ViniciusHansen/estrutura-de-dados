#include "arvore_avl.h"
#include "lista.h"
#include <stdlib.h>

int maior(int x, int y) {
    return x > y ? x : y;
}

int altura(Nodo_ABB* nodo) {
    if ( nodo == NULL )
        return -1;
    return nodo->altura;
}
 
int balanceamento(Nodo_ABB* nodo) {
    return altura(nodo->esquerda) - altura(nodo->direita);
}

int chave_maior(long chave, Nodo_ABB* nodo) {
    if(nodo == NULL)
        return 0;
    return chave > nodo->chave;
}

int chave_menor(long chave, Nodo_ABB* nodo) {
    if(nodo == NULL)
        return 0;
    return chave < nodo->chave;
}

int chave_igual(long chave, Nodo_ABB* nodo) {
    if(nodo == NULL)
        return 0;
    return chave == nodo->chave;
}

Arvore* criar_arvore() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

Nodo_ABB* buscar_aux(Nodo_ABB* nodo, long chave) {
    if ( nodo == NULL )
        return NULL;

    if ( chave_maior(chave, nodo) )
        return buscar_aux(nodo->direita, chave);

    if ( chave_menor(chave, nodo) )
        return buscar_aux(nodo->esquerda, chave);

    return nodo;
}

Lista* arvore_buscar(Arvore* arvore, long chave) {
    Nodo_ABB* nodo = buscar_aux(arvore->raiz, chave);
    if ( nodo == NULL )
        return NULL;
    return nodo->ocorrencias;
}

void destruir_aux(Nodo_ABB* nodo) {
    if( nodo == NULL )
        return;

    Nodo_ABB* esquerda = nodo->esquerda;
    Nodo_ABB* direita = nodo->direita;

    destruir_LDE(nodo->ocorrencias);
    free(nodo);

    destruir_aux(esquerda);
    destruir_aux(direita);
}

Arvore* destruir_arvore(Arvore* arvore) {
    destruir_aux(arvore->raiz);
    free(arvore);
    arvore = NULL;
    return arvore;
}

Nodo_ABB* criar_nodo(long chave, int linha) {
    Nodo_ABB* nodo = (Nodo_ABB*)malloc(sizeof(Nodo_ABB));
    nodo->chave = chave;
    nodo->direita = NULL;
    nodo->esquerda = NULL;
    nodo->altura = 0;
    nodo->ocorrencias = criar_LDE();
    inserir_LDE(nodo->ocorrencias, linha);
    return nodo;
}

void rotac_RR(Nodo_ABB* p){
    Nodo_ABB* q = p->direita;
    q->esquerda = p;
    p = q;
}

void rotac_LL(Nodo_ABB* p){
    Nodo_ABB* q = p->esquerda;
    q->direita = p;
    p = q;
}

void rotac_RL(Nodo_ABB* p){
    Nodo_ABB* q = p->direita;
    Nodo_ABB* r = q->esquerda;
    r->direita = q;
    q = r;
    rotac_RR(p);
}

void rotac_LR(Nodo_ABB* p){
    Nodo_ABB* q = p->esquerda;
    Nodo_ABB* r = q->direita;
    r->esquerda = q;
    q = r;
    rotac_LL(p);
}

Nodo_ABB* inserir_aux(Nodo_ABB* nodo, long chave, int linha) {
    if ( nodo == NULL ) {
        nodo = criar_nodo(chave, linha);
        return nodo;
    }
    
    if ( chave_igual(chave, nodo) ) {
        inserir_LDE(nodo->ocorrencias, linha);
        return nodo;   
    }else if ( chave_menor(chave, nodo) )
        nodo->esquerda = inserir_aux(nodo->esquerda, chave, linha);
    
    else if ( chave_maior(chave, nodo) )
        nodo->direita = inserir_aux(nodo->direita, chave, linha);
    
    nodo->altura = maior(altura(nodo->esquerda), altura(nodo->direita)) + 1;

    if ( balanceamento(nodo) > 1 && chave < nodo->esquerda->chave)
        rotac_RR(nodo);
    
    if ( balanceamento(nodo) < -1  && chave > nodo->direita->chave)
        rotac_LL(nodo);
    
    if ( balanceamento(nodo) > 1 && chave > nodo->esquerda->chave)
        rotac_LR(nodo);
    
    if ( balanceamento(nodo) < -1 && chave < nodo->direita->chave)
        rotac_RL(nodo);
    


    return nodo;
}

void arvore_inserir(Arvore* arvore, long chave, int linha) {
    arvore->raiz = inserir_aux(arvore->raiz, chave, linha);
}