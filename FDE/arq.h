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

int insereNaFila(Elemento *novo, descF *p);

int tamanhoDaFila(descF *p);

int reinicia(descF *p);

descF* destroi(descF *p);

int buscaNaCauda(Elemento *reg, descF *p);

int buscaNaFrente(Elemento *reg, descF *p);

int buscaNoRefMovelFrente(Elemento *reg, descF *p);

int retiraDaFila(Elemento *reg, descF *p);

int testaVazia(descF *p);

int inverte(descF *p);

descF* destroi(descF *p);
