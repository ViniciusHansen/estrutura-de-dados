typedef struct elem{
    int valor;
    int prioridade;
    struct elem* prox;
    struct elem* ant;
}Elemento;

typedef struct descritor{
    int TamLista;
    int TamInfo;
    Elemento cauda;
    Elemento frente;
    Elemento ref_movel;
}descF;

descF* cria(int tamInfo);

int insereNaFila(info *novo,struct descF *p);

int tamanhoDaFila(struct descF *p);

int reinicia(struct descF *p);

descF* destroi(struct descF *p);

int buscaNaCauda(info *reg, struct descF *p);

int buscaNaFrente(info *reg, struct descF *p);

int buscaNoRefMovelFrente(info *reg, struct descF *p);

int retiraDaFila(info *reg, struct descF *p);

int testaVazia(struct descF *p);

int inverte(struct descF *p);

descF* destroi(struct descF *p);
