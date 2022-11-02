#include <stdlib.h>

typedef struct Elemento {
    int valor;
    int prioridade;
    struct Elemento* prox;
    struct Elemento* ant;
} Elemento;

typedef struct Descritor {
    int tam_atual;
    int tam_max; 
    Elemento* cauda;
    Elemento* frente;
    Elemento* ref_movel;
} Descritor;

Descritor* cria(int tam_max);

int insereNaFila(Elemento *novo, Descritor *fila);

int tamanhoDaFila(Descritor *fila);

int vazia(Descritor *fila);

void reinicia(Descritor *fila);

void destroi(Descritor *fila);

int* buscaNaCauda(Elemento *elem, Descritor *fila);

int* buscaNaFrente(Elemento *elem, Descritor *fila);

int* buscaNoRefMovelFrente(Elemento *elem, Descritor *fila);

Elemento* retiraDaFila(Descritor* fila);

int inverte(Descritor *fila);

