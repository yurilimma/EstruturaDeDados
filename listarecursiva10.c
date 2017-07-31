#include<stdio.h>
#include<stdlib.h>


int cont=0;
void func (int k,int num)
{
  int a,b;

  a= k%10;

  b=(int)(k-a)/10;

  if(b<=0)
   return;
   else
   {
     if(a==num)
      cont++;
     return (func(b,num));
   }

}
int main()
{
 int valor,chave,resp;
 printf("Informe um numero \n");
 scanf("%d", &valor);
 printf("Informe o digito a ser pesquisado \n");
 scanf("%d", &chave);
 func(valor,chave);
 printf("O digito %d aparece %d vezes no digito %d \n", chave,cont,valor );
 system("pause");
 return 0;
}
