#include <stdio.h>
#include <stdlib.h>
int soma_digitos(int num)
{
    int a,b;

    //Atribuição do valor do ultimo digito do número à variável "a".
    a = num%10; //manda o que esta depois da virgula no quociente

     //Remoção o ultimo dígito do número "num" e atribui o novo valor para "b"
    b = (int)(num - a)/10; //manda o que esta antes da virgula no quociente

    //Testa se o número ainda tem mais algum dígito ou não. Se não tiver, então é retornado só o valor do próprio dígito.
    if (b <= 0)
      return a;
    else
      return a + soma_digitos(b);     // Se tiver mais algum dígito. Soma o valor do último número ao próximo ultimo número.
}
int main()
{
 int n,total;
 printf ("Informe o numero: \n");
 scanf ("%d",&n);
 total=soma_digitos(n);
 printf ("A Soma dos digitos do numero %d e: %d \n",n,total);
 system("pause");
 return 0;

}
