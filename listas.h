#include<stdio.h>
#include<stdlib.h>

struct lista
{
  int info;
  struct lista *prox;


};typedef struct lista Lista;

Lista *lst_insere(Lista *p,int num)
{
  Lista *novo=(Lista*) malloc(sizeof(Lista));
  novo->info=num;
  novo->prox=p;
  return novo;
}
Lista *lst_cria()
{
  return NULL;
}
Lista *lst_separa(Lista *l, int chave)
{
 Lista *p;
 Lista *aux;
 for(p=l;p!=NULL;p=p->prox)
  if(p->info==chave)
  {
   aux=p->prox;
   p->prox=NULL;
   return aux;
  }

}
void *lst_imprime(Lista *l1)
{
  Lista *p;
  for(p=l1;p!=NULL;p=p->prox)
   printf("%d \n", p->info);

}
