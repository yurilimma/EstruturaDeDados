#include"listas.h"

int main()
{

 Lista *l2,*l1;
 l1=lst_cria();
 l1=lst_insere(l1,29);
 l1=lst_insere(l1,32);
 l1=lst_insere(l1,55);
 l1=lst_insere(l1,80);
 l1=lst_insere(l1,85);
 l1=lst_insere(l1,88);
 l1=lst_insere(l1,89);
 l1=lst_insere(l1,98);
 l1=lst_insere(l1,108);
 l1=lst_insere(l1,118);
 l2=lst_separa(l1,88);
 lst_imprime(l1);



 system("pause");
 return 0;
}
