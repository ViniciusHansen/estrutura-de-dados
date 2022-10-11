
//Amyr e Vinicius Hansen
#include <stdio.h>
#include "pe.h"
#include "pse.h"

float pos_fixa(char* expressao);

int main() {
	PSE* pse = cria_PSE();
	char expressao[] = "234*+";
	int i;
	for(i = 0; i < 5; i++)
		stack_PSE(pse, i);
	PE* pe = PSE_PE(pse);
	for(i = 0; i < 5; i++) {
		printf("%d\n", *peek_PE(pe));
		pop_PE(pe);
	}
	printf("Pos fixa: %f", pos_fixa(expressao));
	getchar();
}
		

float pos_fixa(char* expressao) {
    PSE *pilha = cria_PSE();
    int i;
    float op1, op2;
    char elem;
    for(i = 0; expressao[i] != '\0'; i++) {
        elem = expressao[i];
        if ( elem == 42 || elem == 43 || elem == 45 || elem == 47 ) {
            op1 = *peek_PSE(pilha);
            pop_PSE(pilha);
            op2 = *peek_PSE(pilha);
            pop_PSE(pilha);
            switch(elem) {
                case 42:
                    stack_PSE(pilha, op2 * op1);
                    break;
                case 43:
                    stack_PSE(pilha, op2 + op1);
                    break;
                case 45:
                    stack_PSE(pilha, op2 - op1);
                    break;
                case 47:
                    stack_PSE(pilha, op2 / op1);
                    break;
            }
        } 
        else
            stack_PSE(pilha, elem - 48);
    }
    return *peek_PSE(pilha);
}
