#include <stdlib.h>
#include "lista.h"

Lista* criar_LDE() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

int vazia(Lista* lista) {
    return lista->tamanho == 0;
}

Lista* destruir_LDE(Lista* lista) {
    Nodo_LDE* temp1 = lista->inicio;
    Nodo_LDE* temp2;

    while ( temp1 != NULL ) {
        temp2 = temp1->proximo;
        free(temp1);
        temp1 = temp2;
    }

    free(lista);
    lista = NULL;
    return lista;
}

void inserir_LDE(Lista* lista, int linha) {
    Nodo_LDE* novo_nodo = (Nodo_LDE*)malloc(sizeof(Nodo_LDE));
    Nodo_LDE* inicio = lista->inicio;

    /*if (lista->inicio == NULL){
        novo_nodo->linha = linha;
        lista->inicio = novo_nodo; 
        novo_nodo->anterior = NULL;
        lista->tamanho = 1;
    }*/
    if ( inicio != NULL )
        inicio->anterior = novo_nodo;
    
    novo_nodo->proximo = inicio;
    novo_nodo->anterior = NULL;
    novo_nodo->linha = linha;
    
    lista->inicio = novo_nodo;
    lista->tamanho += 1;
}

int remover_LDE(Lista* lista, int linha) {
    if ( vazia(lista) )
        return 0;

    int encontrado = 0;
    Nodo_LDE* temp1 = lista->inicio;
    //Nodo_LDE* temp2;

    while( temp1 != NULL && !encontrado) {

        if ( temp1->linha == linha ) {

            if ( temp1->proximo != NULL ) //antes era temp->proximo != NULL
                temp1->proximo->anterior = temp1->anterior;
                
            if ( temp1->anterior != NULL )
                temp1->anterior->proximo = temp1->proximo;

            free(temp1);
            encontrado = 1;;
            lista->tamanho -= 1;
        }
        if ( !encontrado )
            temp1 = temp1->proximo;
    }
    
    return encontrado;
}

void printaLDE(Lista* lista){
    Nodo_LDE* aux = lista->inicio;
    while(aux != NULL){
        printf("%i\n", aux->linha);
        aux = aux->proximo;
    }
}
