

descF* cria(int tamanho){
    descF* new;
    new.TamLista = tamanho;
    new.cauda = NULL;
    new.frente = NULL;
    new.ref_movel == NULL;
    return new;
}

int insereNaFila(Elemento *novo, descF *p){
    p->cauda = novo;
    p->cauda->ant = NULL;
    p->ref_movel = novo;
    // como determinar o elem da frente?
    return 1;
}
