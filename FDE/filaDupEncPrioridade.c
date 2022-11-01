

descF* cria(int tamanho){
    descF* new = (descF*)malloc(sizeof(descF*));
    new->TamLista = tamanho; //TamInfo ou TamLista?
    new->cauda = NULL;
    new->frente = NULL;
    new->ref_movel == NULL;
    return new;
}

void insereNaFila(Elemento *novo, descF *f){
    f->cauda = novo;
    f->cauda->ant = NULL;
    f->ref_movel = novo;
    f->frente = f->ref_movel;
    // como determinar o elem da frente?
}

int tamanhoDaFila(descF *f){
    int count = 0;
    descF *p = f->cauda;
    while(p != NULL){
        count++;
        p = p->prox;
    }
    return count;
}

int vazia(descF *f){
    return (f->cauda==NULL && f->frente==NULL && f-> ref_movel==NULL);
}

int reinicia(descF *f){
    descF *p = f->cauda;
    while(p->prox != NULL){
        free(p);
        p = p->prox;
    }
}

void destroi(descF *f){
    free(f);
}

int buscaNaCauda(Elemento *reg, descF *f){


}
