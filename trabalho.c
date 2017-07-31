#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *vetor,int tam);
void Merge(int *A,int *Esq,int tamEsq,int *Dir,int tamDir);
void imprimeVet(int tam , int *vetor);
void bubbleSort(int tam, int *vetor);
void selectionSort(int tam, int *vetor);
void insertionSort(int tam, int *vetor);

void imprimeVet(int tam , int *vetor)
{
  int i,chave;
  for(i=0; i<tam; i++)
    printf("%d \t", vetor[i]);
  system("pause");
  printf("\n1 – Bubble Sort (Complexidade O(n^2) \n2 – SelectionSort (Complexidade O(n^2)\n3 – InsertionSort (Complexidade O(n^2)\n4 – MergeSort (Complexidade O(nLogn)\n0 – Sair\n");
  scanf("%d", &chave);
  vetor[0]=0;
  vetor[1]=24;
  vetor[2]=12;
  vetor[3]=5;
  vetor[4]=15;
  printf("\nO vetor foi embaralhado e ficou assim\n");
  for(i=0; i<tam; i++)
    printf("%d \t", vetor[i]);

 if(chave==1)
  bubbleSort(tam,vetor);
 if(chave==2)
  selectionSort(tam,vetor);
 if(chave==3)
  insertionSort(tam,vetor);
 if(chave==4)
  mergeSort(vetor,tam);
 if(chave==0)
  exit(-1);




}

void bubbleSort(int tam, int *vetor)
{
 int c, d, t;

  for (c = 0 ; c < ( tam - 1 ); c++)
  {
    for (d = 0 ; d < tam - c - 1; d++)
    {
      if (vetor[d] > vetor[d+1])
      {
        t         = vetor[d];
        vetor[d]   = vetor[d+1];
        vetor[d+1] = t;
      }
    }
  }
  printf("\nCom o metodo BubbleSort o vetor ficou: \n");
  imprimeVet(tam,vetor);
  return;


}
void selectionSort(int tam, int *vetor)
{
  int menor, aux,j,i;
  for(i=0;i<tam-1;i++)
  {
      menor=i;
      for(j=i+1;j<tam;j++)
        if(vetor[j]<vetor[menor])
          menor=j;
      if(i!=menor)
      {
        aux=vetor[i];
        vetor[i]=vetor[menor];
        vetor[menor]=aux;
      }
  }
  printf("\nCom o metodo SelectionSort o vetor ficou: \n");
  imprimeVet(tam,vetor);
  return;
}
void insertionSort(int tam, int *vetor)
{
  int aux,i,j;
  for(j=0;j<tam;j++)
  {
    aux=vetor[j];
    i=j-1;
    while((i>=0)&&(vetor[i]>aux))
    {
      vetor[i+1]=vetor[i];
      vetor[i]=aux;
      i--;
    }
   }
  printf("\nCom o metodo InsertionSort o vetor ficou: \n");
  imprimeVet(tam,vetor);
  return;
}
void Merge(int *A,int *Esq,int tamEsq,int *Dir,int tamDir)
{
  int i,j,k;
  i = 0; j = 0; k =0;
  while(i<tamEsq && j< tamDir)
  {
     if(Esq[i] < Dir[j])
       A[k++] = Esq[i++];
     else
       A[k++] = Dir[j++];
   }
   while(i < tamEsq)
    A[k++] = Esq[i++];
   while(j < tamDir)
    A[k++] = Dir[j++];

}

void mergeSort(int *vetor,int tam)
{
   int meio,i, *Esq, *Dir;
   if(tam < 2)
    return; // condicao base
   meio = tam/2; // procura o indice do meio
   // cria os vetores Esquerdo e Direito
   Esq = (int*)malloc(meio*sizeof(int));
   Dir = (int*)malloc((tam-meio)*sizeof(int));
   for(i = 0;i<meio;i++)
      Esq[i] = vetor[i];
   for(i = meio;i<tam;i++)
      Dir[i-meio] = vetor[i];
   mergeSort(Esq,meio);
   mergeSort(Dir,(tam-meio));
   Merge(vetor,Esq,meio,Dir,tam-meio);
   printf("\nCom o metodo MergeSort o vetor ficou: \n");
   imprimeVet(5,vetor);
   return;

}





int main()
{
 int chave,vetor[5]={0,12,5,24,15},i;
 printf("1 – Bubble Sort (Complexidade O(n^2) \n2 – SelectionSort (Complexidade O(n^2)\n3 – InsertionSort (Complexidade O(n^2)\n4 – MergeSort (Complexidade O(nLogn)\n0 – Sair\n");
 scanf("%d", &chave);
 printf("O vetor esta assim: \n");
 for(i=0;i<5;i++)
  printf("%d \t", vetor[i]);
 if(chave==1)
  bubbleSort(5,vetor);
 if(chave==2)
  selectionSort(5,vetor);
 if(chave==3)
  insertionSort(5,vetor);
 if(chave==4)
  mergeSort(vetor,5);



 system("pause");
 return 0;
}
