typedef struct NO *ArvBin;
struct NO
{
  int info;
  struct NO *esq;
  struct NO *dir;
}; ArvBin *raiz;

ArvBin *cria_arvbin()
{
    ArvBin *raiz=(ArvBin*)malloc(sizeof(ArvBin));
    if(raiz!=NULL)
     *raiz=NULL;
    return raiz;
}
void libera_no(struct NO *no)
{
    if(no==NULL)
      return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no=NULL;
}
void libera_arvbin(ArvBin* raiz)
{
   if(raiz==NULL)
    return;
   libera_no(*raiz);
   free(raiz);

}
int insere_ArvBin(ArvBin* raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else
     {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            if(valor == atual->info)
            {
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}
void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

int pares(ArvBin *a)
{
    if(a==NULL)
     return 0;
    if(*a==NULL)
     return 0;
    if((*a)->info%2==0)
     return(1+ pares(&(*a)->esq) + pares(&(*a)->dir));
     else
      return(0+ pares(&(*a)->esq) + pares(&(*a)->dir));
}

int folhas(ArvBin *a)
{
    if(a==NULL)
     return 0;
    if(*a==NULL)
     return 0;
    int cont_esq=folhas(&(*a)->esq);
    int cont_dir=folhas(&(*a)->dir);
    return (cont_esq + cont_dir + 1);
}

int um_filho (ArvBin *a)
{
    if(a==NULL)
     return 0;
    if(*a==NULL)
     return 0;
    if((*a)->esq
    um_filho(&(*a)->esq);
    um_filho(&(*a)->dir);

}

int igual (ArvBin *a, ArvBin *b)
{
    if(a==NULL)
     return 0;
    if(*a==NULL)
     return 0;
    if((*a)->info==(*b)->info)
     return (1 + igual(&(*a)->esq,(&(*b)->esq)) + igual((&(*a)->dir),(&(*b)->dir)));
    else
     return 0;


}
