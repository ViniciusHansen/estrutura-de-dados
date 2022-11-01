#include <stdlib.h>

typedef struct elem{
    int valor;
    int prioridade;
    struct elem* prox;
    struct elem* ant;
}Elemento;

typedef struct descritor{
    int TamLista;
    int TamInfo; //pra que serve isso?
    Elemento* cauda;
    Elemento* frente;
    Elemento* ref_movel;
}descF;

descF* cria(int tamInfo);

int insereNaFila(Elemento *novo, descF *f);

int tamanhoDaFila(descF *f);

int reinicia(descF *f);

descF* destroi(descF *f);

int buscaNaCauda(Elemento *reg, descF *f);

int buscaNaFrente(Elemento *reg, descF *f);

int buscaNoRefMovelFrente(Elemento *reg, descF *f);

int retiraDaFila(Elemento *reg, descF *f);

int testaVazia(descF *f);

int inverte(descF *f);

