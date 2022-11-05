#include <stdlib.h>
#include <stdio.h>
#include "arq.h"

int main() {
    Descritor* fila = cria(6);
    insereNaFila(&(Info){"Bruno", 10}, fila);
    insereNaFila(&(Info){"Thiago", 20}, fila);
    insereNaFila(&(Info){"Joao", 21}, fila);
    insereNaFila(&(Info){"Amyr", 20}, fila);
    int i;
    int teste;
    Info temp;
    for(i = 0; i < tamanhoDaFila(fila); i++) {
        if ( retiraDaFila(&temp, fila) )
            printf("Nome: %s, Idade: %d", temp.nome, temp.idade);
    }
    scanf("%d", &teste);
    return 0;
}