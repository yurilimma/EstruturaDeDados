#include <stdio.h>
#include <conio.h> 
int fibonacci(int num)
{
   if(num==1 || num==2)
       return 1;
   else
       return fibonacci(num-1) + fibonacci(num-2); 
}

int main()
{
   int n,i;
   printf("Digite a quantidade de termos da sequência de Fibonacci: ");
   scanf("%d", &n);
   printf("\nA sequencia de Fibonacci eh: \n");
   for(i=0; i<n; i++)
       printf("%d ", fibonacci(i+1));
   getch();
} 

