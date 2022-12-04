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
    return chave > nodo->chave;
}

int chave_menor(long chave, Nodo_ABB* nodo) {
    return chave < nodo->chave;
}

int chave_igual(long chave, Nodo_ABB* nodo) {
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

void rotac_direita(Nodo_ABB* nodo) {
    Nodo_ABB* temp = nodo->esquerda;
    nodo->esquerda = nodo->esquerda->direita;
    temp->direita = nodo;
    nodo->altura = maior(altura(nodo->esquerda), altura(nodo->direita)) + 1;
    temp->altura = maior(altura(temp->esquerda), altura(temp->direita)) + 1;
}

void rotac_esquerda(Nodo_ABB* nodo) {
    Nodo_ABB* temp = nodo->direita;
    nodo->direita->esquerda = nodo->direita;
    temp->esquerda = nodo;
    nodo->altura = maior(altura(nodo->esquerda), altura(nodo->direita)) + 1;
    temp->altura = maior(altura(temp->esquerda), altura(temp->direita)) + 1;
}


Nodo_ABB* inserir_aux(Nodo_ABB* nodo, long chave, int linha) {
    if ( nodo == NULL ) {
        nodo = criar_nodo(chave, linha);
        return nodo;
    } else if ( chave_igual(chave, nodo) ) {
        inserir_LDE(nodo->ocorrencias, linha);
        return nodo;   
    }

    if ( chave_menor(chave, nodo) )
        nodo->esquerda = inserir_aux(nodo->esquerda, chave, linha);
    
    else if ( chave_maior(chave, nodo) )
        nodo->direita = inserir_aux(nodo->direita, chave, linha);
    
    nodo->altura = maior(altura(nodo->esquerda), altura(nodo->direita)) + 1;

    if ( balanceamento(nodo) < -1 )
        rotac_esquerda(nodo);
    
    else if ( balanceamento(nodo) > 1 )
        rotac_direita(nodo);

    return nodo;
}

void arvore_inserir(Arvore* arvore, long chave, int linha) {
    arvore->raiz = inserir_aux(arvore->raiz, chave, linha);
}