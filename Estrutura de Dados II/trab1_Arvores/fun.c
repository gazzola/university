void inserir(raiz *r, int x){

	if((*r)==NULL){
		no *novo = (no*)malloc(sizeof(no));
		novo->esq=novo->dir=NULL;
		novo->dado = x;
		(*r) = novo;
	}else if(x >= (*r)->dado)
		inserir(&(*r)->dir, x);
	else
		inserir(&(*r)->esq, x);
}

void em_ordem(raiz *r){
	if((*r)==NULL)
		return;

	if((*r)->esq != NULL)
		em_ordem(&(*r)->esq);

	printf("%d ", (*r)->dado);

	if((*r)->dir != NULL)
		em_ordem(&(*r)->dir);
}

void pre_ordem(raiz *r){
	if((*r)==NULL)
		return;

	printf("%d ", (*r)->dado);

	if((*r)->esq != NULL)
		pre_ordem(&(*r)->esq);

	if((*r)->dir != NULL)
		pre_ordem(&(*r)->dir);
}

void pos_ordem(raiz *r){
	if((*r)==NULL)
		return;

	if((*r)->esq != NULL)
		pos_ordem(&(*r)->esq);

	if((*r)->dir != NULL)
		pos_ordem(&(*r)->dir);

	printf("%d ", (*r)->dado);

}
