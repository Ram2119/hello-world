#include <stdio.h>

int main(void)
{
	int a = 23;
	int b = 5;


	printf("%d/%d = ", a, b);

	int div = 0;
	while (a >= b) {
		div++;
		a -= b;	
	}

	printf("%d\n", div);

	return 0;
}
