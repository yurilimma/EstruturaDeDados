#include <stdio.h>
#include <stdlib.h>
int fat(int num);

int main()
{
	int n;
		printf("Informe um valor a ser fatoriado: ");
		scanf("%d", &n);
			printf("O resultado = %d\n", fat(n));			


    system("PAUSE");
return 0;
}

int fat(int n)
{
	if(n==0)
		return 1;
	else
		return n*fat(n-1);	
	
	
}
