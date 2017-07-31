#include<stdio.h>
#include<stdlib.h>

struct lista
{
  int info;
  struct lista *prox;

};typedef struct lista Lista;

Lista *lst_insere(Lista *v, int num)
{
  Lista *p=(Lista*)malloc(sizeof(Lista));
  p->info=num;
  p->prox=v;
  return p;
}
Lista *lst_cria()
{
  return NULL;
}
void *lst_libera(Lista *p)
{
  Lista *n=p;
  while(n!=NULL)
  {
    Lista *t=n->prox; //guardar o enedereco do proximo no
    free(n);
    n=t;
  }
}
Lista *lst_removepref(Lista *v, int num)
{
  int cont=0;
  Lista *p=v;
  while(p!=NULL)
  {
    cont++;
    p=p->prox;
   }
  if(num>cont)
   lst_libera(v);
   else
   {
    p=v;
    while(num!=0)
    {
      p=v->prox; //auxiliar para guardar o endereco do prox elemento
      free(v); //liberar o v
      num--; //decrementando o num pra sair do while
      v=p; //passando o endereco do prox elemento pro v
    }
    return v;
   }
}

void *lst_imprime(Lista *v)
{
  while(v!=NULL)
  {
   printf("%d \n", v->info);
   v=v->prox;
  }
}

int main()
{
  Lista *l1;
  l1=lst_cria();
  l1=lst_insere(l1,5);
  l1=lst_insere(l1,25);
  l1=lst_insere(l1,35);
  l1=lst_insere(l1,45);
  l1=lst_insere(l1,55);
  l1=lst_removepref(l1,2);
  lst_imprime(l1);



  system("pause");
  return 0;
}
