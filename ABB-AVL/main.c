#include <stdio.h>
#include <string.h>
#include "arvore_avl.h"
#include "lista.h"

long hash(char *str);

int main() {
    Arvore* arvore = criar_arvore();
    FILE* arquivo = fopen("arq.txt", "r");
    char linha[256];
    char* token;
    char delimitador[2] = {' '};
    int contagem_linha = 0;

    while( fgets(linha, sizeof(linha), arquivo) ) {
        contagem_linha += 1;
        token = strtok(linha, delimitador);
        while( token != NULL ) {
            if ( token[0] >= 65 && token[0] <= 90 )
                arvore_inserir(arvore, hash(token), contagem_linha);
            token = strtok(NULL, delimitador); 
        }
    }
                   
}

long hash(char* str) {
    long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}