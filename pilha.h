struct lista
{
   int info;
   struct lista *prox;
};typedef struct lista Lista;
struct pilha
{
  Lista *prim;
};typedef struct pilha Pilha;
Pilha *pilha_cria()
{
 Pilha *p=(Pilha*)malloc(sizeof(Pilha));
 p->prim=NULL;
 return p;

}
Pilha *pilha_vazia(Pilha *p)
{
    if(p->prim==NULL) //p->prim porque e o prim que aponta
     return 1;
    else
      return 0;
}

void pilha_libera(Pilha *p)
{
  Lista *q= p->prim;
  while(q!=NULL)
  {
    Lista *t=q->prox;
    free(q);
    q=t;
  }
}
float pilha_pop(Pilha *p)
{
 Lista *t;
 float v;
 if(pilha_vazia(p))
 {
   printf("Pilha vazia \n");
   exit(1);
 }
 t=p->prim; //passa pra onde a pilha esta apontando
 v=t->info; //passa o valor
 p->prim=t->prox; //troca os ponteiros
 free(t);
 return v;
 }
 void pilha_push(Pilha *p,float v)
 {
   Lista *n=(Lista*)malloc(sizeof(Lista));
   n->info=v;
   n->prox=p->prim;
   p->prim=n; //o topo agora aponta pro novo elemento da pilha
 }

