#include <stdio.h>
int expo (int x, int y)
{
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
		
	return x*expo(x,y-1);
}
int main(void) {
int x=2, y=2, e;
e=expo(x,y);
printf("\n\nX elevado a y eh: %d\n", e); 


system("Pause");
return 0;

}
