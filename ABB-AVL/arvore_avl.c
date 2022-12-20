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
        nodo->direita = buscar_aux(nodo->direita, chave);

    else if ( chave_menor(chave, nodo) )
        nodo->esquerda = buscar_aux(nodo->esquerda, chave);
    
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
    p->direita = q->esquerda;
    q->esquerda = p;
    p->altura = maior(altura(p->esquerda), altura(p->direita)) + 1;
    q->altura = maior(altura(q->esquerda), altura(q->direita)) + 1;
    p = q;
}

void rotac_LL(Nodo_ABB* p){
    Nodo_ABB* q = p->esquerda;
    p->esquerda = q->direita;
    q->direita = p;
    p->altura = maior(altura(p->esquerda), altura(p->direita)) + 1;
    q->altura = maior(altura(q->esquerda), altura(q->direita)) + 1;
    p = q;
}

void rotac_RL(Nodo_ABB* p){
    Nodo_ABB* q = p->direita;
    Nodo_ABB* r = q->esquerda;
    p->direita = r->esquerda;
    q->esquerda = r->direita;
    r->direita = q;
    r->esquerda = p;
    p->altura = maior(altura(p->esquerda), altura(p->direita)) + 1;
    q->altura = maior(altura(q->esquerda), altura(q->direita)) + 1;
    r->altura = maior(altura(r->esquerda), altura(r->direita)) + 1;
    p = r;
}

void rotac_LR(Nodo_ABB* p){
    Nodo_ABB* q = p->esquerda;
    Nodo_ABB* r = q->direita;
    p->esquerda = r->direita;
    q->direita = r->esquerda;
    r->esquerda = q;
    r->direita = p;
    p->altura = maior(altura(p->esquerda), altura(p->direita)) + 1;
    q->altura = maior(altura(q->esquerda), altura(q->direita)) + 1;
    r->altura = maior(altura(r->esquerda), altura(r->direita)) + 1;
    p = r;
}

Nodo_ABB* inserir_aux(Nodo_ABB* nodo, long chave, int linha) {
    if ( nodo == NULL )
        return criar_nodo(chave, linha);
    
    if ( chave_igual(chave, nodo) ) {
        inserir_LDE(nodo->ocorrencias, linha);
        return nodo;   
    }else if ( chave_menor(chave, nodo) )
        nodo->esquerda = inserir_aux(nodo->esquerda, chave, linha);
    
    else if ( chave_maior(chave, nodo) )
        nodo->direita = inserir_aux(nodo->direita, chave, linha);
    
    nodo->altura = maior(altura(nodo->esquerda), altura(nodo->direita)) + 1;

    if ( balanceamento(nodo) > 1 && chave < nodo->esquerda->chave)
        rotac_LL(nodo);
    
    if ( balanceamento(nodo) < -1  && chave > nodo->direita->chave)
        rotac_RR(nodo);
    
    if ( balanceamento(nodo) > 1 && chave > nodo->esquerda->chave)
        rotac_LR(nodo);
    
    if ( balanceamento(nodo) < -1 && chave < nodo->direita->chave)
        rotac_RL(nodo);

    return nodo;
}

void arvore_inserir(Arvore* arvore, long chave, int linha) {
    arvore->raiz = inserir_aux(arvore->raiz, chave, linha);
}

