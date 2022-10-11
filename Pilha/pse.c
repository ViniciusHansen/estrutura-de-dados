
#include <stdlib.h>
#include "pse.h"
#include "pe.h"

PSE* cria_PSE() {
    PSE* pilha = (PSE*)malloc(sizeof(PSE));
    pilha->topo = NULL;
    pilha->tam = 0;
    return pilha;
}

void stack_PSE(PSE* pilha, int valor) {
    Elem *elem = (Elem*)malloc(sizeof(Elem));
    elem->baixo = pilha->topo;
    elem->valor = valor;
    pilha->topo = elem;
    pilha->tam += 1;
}

int pop_PSE(PSE* pilha) {
    if ( pilha->tam == 0 )
        return 0;
    Elem *temp = pilha->topo;
    pilha->topo = pilha->topo->baixo;
    pilha->tam -= 1;
    free(temp);
    return 1;
}

int PSE_vazia(PSE* pilha) {
    return pilha->topo == NULL;
}

int* peek_PSE(PSE* pilha) {
    if ( pilha->tam == 0 )
        return NULL;
    return &pilha->topo->valor;
}

PE* PSE_PE(PSE* pse) {
    if ( pse->tam == 0 )
        return NULL;
    PSE* aux = cria_PSE();
    PE* final = cria_PE((pse->tam) + 3);
    Elem* temp = pse->topo;
    
    do {
    	stack_PSE(aux, temp->valor);
    	temp = temp->baixo;
	} while ( temp != NULL );
	
	temp = aux->topo;
	
	do {
		stack_PE(final, temp->valor);
		temp = temp->baixo;
	} while ( temp != NULL );
	
	return final;
}
