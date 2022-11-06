#include <stdlib.h>
#ifndef FILA_ENCAD
#define FILA_ENCAD

typedef struct {
    char* nome;
    int idade;
} Info;

typedef struct Elemento{
    Info dados;
    int prioridade;
    struct Elemento* prox;
    struct Elemento* ant;
} Elemento;

typedef struct {
    int tam_atual;
    int tam_max; 
    Elemento* cauda;
    Elemento* frente;
    Elemento* ref_movel;
} Descritor;


Descritor* cria(int tam_max);

int insereNaFila(Info* novo, Descritor *fila);

int tamanhoDaFila(Descritor *fila);

int cheia(Descritor *fila);

int vazia(Descritor *fila);

void reinicia(Descritor *fila);

void destroi(Descritor *fila);

int buscaNaCauda(Info* copia, Descritor *fila);

int buscaNaFrente(Info* copia, Descritor *fila);

int buscaNoRefMovel(Info* copia, Descritor *fila);

int retiraDaFila(Info* copia, Descritor* fila);

int inverte(Descritor *fila);

#endif