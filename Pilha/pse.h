
#ifndef PSE_H
#define PSE_H
#include "pe.h"

typedef struct elem {
    struct elem* baixo;
    int valor;
} Elem;

typedef struct PSE {
    Elem* topo;
    int tam;
} PSE;

PSE* cria_PSE();
PE* PSE_PE(PSE* pse);
void stack_PSE(PSE* pilha, int valor);
int pop_PSE(PSE* pilha);
int PSE_vazia(PSE* pilha);
int* peek_PSE(PSE* pilha);

#endif
