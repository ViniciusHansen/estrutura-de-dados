
#include <stdlib.h>
#include "pe.h"

PE* cria_PE(int tam) {
    PE* pilha = (PE*)malloc(sizeof(PE));
    pilha->dados = (int*)malloc(sizeof(int) * tam);
    pilha->topo = -1;
    pilha->tam = 0;
    pilha->tam_max = tam;
    return pilha;
}

int stack_PE(PE* pilha, int elem) {
    if ( pilha->tam == pilha->tam_max )
        return 0;
    pilha->tam += 1;
    pilha->topo += 1;
    pilha->dados[pilha->topo] = elem;
    return 1;
}

int pop_PE(PE* pilha) {
    if ( pilha->tam == 0 )
        return 0;
    pilha->tam -= 1;
    pilha->topo -= 1;
    return 1;
}

int* peek_PE(PE* pilha) {
    if ( pilha->tam == 0 )
        return NULL;
    return &(pilha->dados[pilha->topo]);
}
