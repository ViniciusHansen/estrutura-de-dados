#include <stdlib.h>
#include "lista.h";

Lista* criar_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

Lista* destruir_lista(Lista* lista) {
    Nodo_LDE* temp1 = lista->inicio;
    Nodo_LDE* temp2;

    while ( temp1 != NULL ) {
        temp2 = temp1->prox
        free(temp1);
        temp1 = temp2;
    }

    free(lista);
    lista = NULL;
    return lista;
}

void lista_inserir(Lista* lista, int linha) {
    Nodo_LDE* novo_nodo = (Nodo_LDE*)malloc(sizeof(Nodo_LDE));
    Nodo_LDE* inicio = lista->inicio

    if ( inicio != NULL )
        inicio->anterior = novo_nodo;
    
    novo_nodo->proximo = inicio;
    novo_nodo->anterior = NULL;
    novo_nodo->linha = linha;
    
    lista->inicio = novo_nodo;
    lista->tamanho += 1;
}

int lista_remover(Lista* lista, int linha) {
    if ( vazia(lista) )
        return 0;

    int encontrado = 0;
    Nodo_LDE* temp1 = lista->inicio;
    Nodo_LDE* temp2;

    while( temp1 != NULL && !encontrado) {

        if ( temp1->linha == linha ) {

            if ( temp->proximo != NULL )
                temp1->proximo->anterior = temp1->anterior;
                
            if ( temp->anterior != NULL )
                temp1->anterior->proximo = temp1->proximo;

            free(temp1);
            encontrado = 1;;
            descritor->tamanho -= 1;
        }
        if ( !encontrado )
            temp1 = temp1->prox;
    }
    
    return encontrado;
}

int vazia(Lista* lista) {
    return lista->tamanho == 0;
}