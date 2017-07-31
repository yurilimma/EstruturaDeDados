/*
 -passos inserir ordenado:
  1-verificar se a lista esta vazia
  2-percorrer a lista até o final guardando o no anterior
    -colocar condicao para parar quando terminar a lista ou encontrar a informacao selecionada
  3-verificar se foi encontrado na primeira posicao
  4-trocar os ponteiros
*/


#include<stdio.h>
#include<stdlib.h>

struct lista
{
  int mat;
  char nome[50];
  float media;
  struct lista *prox;

};typedef struct lista Lista;

Lista *lst_insere_ordenado(Lista *v,int mat, char *nome,float media)
{
  Lista *ant=NULL;
  Lista *p=v;
  Lista *t=(Lista*)malloc(sizeof(Lista));
  t->mat=mat;
  strcpy(t->nome,nome);
  t->media=media;
  t->prox=NULL;
  if(p==NULL) //se a lista estiver vazia
  {
      return t;
  }
  while((p!=NULL) &&(mat>p->mat)) //percorre a lista ate encontrar a matricula menor guardando o valor anterior
  {
     ant=p;
     p=p->prox;
   }
  if(ant==NULL) //se estava na primeira posicao
  {
    t->prox=p;
    return t; //retorna o t porque foi encontrado na primeira posicao
  }
  t->prox=ant->prox; //so cai aqui se entrar no while
  ant->prox=t;
  return v; //como e ponteiro posso retornar o v e na hora de imprimir vai aparecer do inicio

}
void lst_imprime(Lista *v)
{
  while(v!=NULL)
  {
    printf("%d \n", v->mat);
    v=v->prox;
  }
}
Lista *lst_cria()
{
    return NULL;
}

int main()
{
  Lista *l1;
  l1=lst_cria();
  l1=lst_insere_ordenado(l1,10,"xx",8);
  l1=lst_insere_ordenado(l1,04,"xx",3);
  l1=lst_insere_ordenado(l1,02,"xx",5);
  l1=lst_insere_ordenado(l1,06,"xx",2);
  l1=lst_insere_ordenado(l1,03,"xx",5);
  lst_imprime(l1);

  system("pause");
  return 0;
}
