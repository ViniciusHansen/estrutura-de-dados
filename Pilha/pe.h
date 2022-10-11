
#ifndef PE_H
#define PE_H

typedef struct PE {
    int* dados;
    int topo;
    int tam;
    int tam_max;
} PE;


PE* cria_PE(int tam);
int stack_PE(PE* pilha, int elem);
int pop_PE(PE* pilha);
int* peek_PE(PE* pilha);

#endif

