#include <stdio.h>

int main(void)
{
	int a = 2;
	int b = 5;

	int c = a + sizeof(++b);

	printf("%d\n", c);
	return 0;
}
