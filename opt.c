#include <stdio.h>

int main(void)
{
	const int a = 10;
	int *p = &a;

	printf("*p before : %d\n", *p);
	
	*p = 100;
	printf("*p after : %d\n", *p);

	return 0;
}
