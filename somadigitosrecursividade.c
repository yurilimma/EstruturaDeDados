#include <stdio.h>
#include <stdlib.h>
int soma_digitos(int num)
{
    int a,b;

    //Atribui��o do valor do ultimo digito do n�mero � vari�vel "a".
    a = num%10; //manda o que esta depois da virgula no quociente

     //Remo��o o ultimo d�gito do n�mero "num" e atribui o novo valor para "b"
    b = (int)(num - a)/10; //manda o que esta antes da virgula no quociente

    //Testa se o n�mero ainda tem mais algum d�gito ou n�o. Se n�o tiver, ent�o � retornado s� o valor do pr�prio d�gito.
    if (b <= 0)
      return a;
    else
      return a + soma_digitos(b);     // Se tiver mais algum d�gito. Soma o valor do �ltimo n�mero ao pr�ximo ultimo n�mero.
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
