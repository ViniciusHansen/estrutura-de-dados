#include <stdlib.h>
#include <stdio.h>
#include "arq.h"

void teste_1(){ // testa as funções tamanho,vazia, cheia e insere
    Descritor* fila1 = cria(10);
    if(vazia(fila1)){
        printf("Tamanho: %i \n", tamanhoDaFila(fila1));
        printf("vazia\n");
    }
    insereNaFila(&(Info){"Ricardo", 12}, fila1);
    insereNaFila(&(Info){"Jaime", 22}, fila1);
    insereNaFila(&(Info){"asdasdas", 32}, fila1);
    insereNaFila(&(Info){"Jaidfgfd", 12}, fila1);
    insereNaFila(&(Info){"Jaasdime", 72}, fila1);
    insereNaFila(&(Info){"Jasdfsdfime", 25}, fila1);
    insereNaFila(&(Info){"Jacbime", 27}, fila1);
    insereNaFila(&(Info){"Jafgime", 28}, fila1);
    insereNaFila(&(Info){"Jonas", 22}, fila1);
    insereNaFila(&(Info){"Jaihjme", 42}, fila1);

    if(cheia(fila1)){
        printf("Tamanho: %i \n", tamanhoDaFila(fila1));
        printf("cheia\n");
    }

    reinicia(fila1);

    if(vazia(fila1)){
        printf("Tamanho: %i \n", tamanhoDaFila(fila1));
        printf("vazia\n");
    }
}

void teste_2(){ //testa funções de busca, inversão e remoção
    Descritor* fila2 = cria(5);
    insereNaFila(&(Info){"Joao", 22}, fila2);
    insereNaFila(&(Info){"Pedro", 19}, fila2);
    insereNaFila(&(Info){"Paulo", 40}, fila2);
    insereNaFila(&(Info){"Enzo", 26}, fila2);
    insereNaFila(&(Info){"Vitor", 12}, fila2);
    Info info_cauda;
    if(buscaNaCauda(&info_cauda, fila2))
        printf("Cauda: \nNome: %s, Idade: %i \n", info_cauda.nome, info_cauda.idade);
    //Info info_ref_movel;
    //if(buscaNoRefMovel(&info_ref_movel, fila2))
    //    printf("Ref Móvel: \nNome: %s, Idade: %i \n",info_ref_movel.nome,info_ref_movel.idade);
    Info info_frente;
    if(buscaNaFrente(&info_frente, fila2))
        printf("Frente: \nNome: %s, Idade: %i \n", info_frente.nome, info_frente.idade);
    
    printf("------Funcao de Inversao------\n");
    if ( inverte(fila2) ) {
        Info temp;
        int i;
        for(i = 0; i < tamanhoDaFila(fila2); i++) {
            retiraDaFila(&temp, fila2);
            printf("Nome: %s, Idade: %i \n", temp.nome, temp.idade);
        }
    }
}

void teste_3() { //testa a função de retirar da fila
    Descritor* fila = cria(6);
    insereNaFila(&(Info){"Bruno", 10}, fila);
    insereNaFila(&(Info){"Thiago", 20}, fila);
    insereNaFila(&(Info){"Joao", 21}, fila);
    insereNaFila(&(Info){"Amyr", 20}, fila);
    int i;
    Info temp;
    for(i = 0; i < tamanhoDaFila(fila); i++) {
        if ( retiraDaFila(&temp, fila) )
            printf("Nome: %s, Idade: %d\n", temp.nome, temp.idade);
    }
    printf("%d\n", tamanhoDaFila(fila));
}

int main() {
    printf("Teste 1:\n");
    teste_1();
    printf("Teste 2:\n");
    teste_2();
    printf("Teste 3:\n");
    teste_3();
    return 0;
}