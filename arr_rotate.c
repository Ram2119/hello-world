
#include <stdio.h>

void rotateByOne(int *a, int size)
{
	int i = 0;
	int tmp = a[0];
	for (; i < size-1; i++)
		a[i] = a[i+1];
	a[i] = tmp;
}

void rotate(int *a, int d, int size)
{
	int i = 0;
	for (; i < d; i++)
		rotateByOne(a, size);
}


void print(int *a, int size)
{
	int i = 0;	
	for (; i < size; i++)
		printf("%d  ", a[i]);	
	printf("\n");
}

int main(void)
{
	int a[] = {2, 3, 5, 20, 10, 40, 30};

	int n = sizeof(a) / sizeof(a[0]);
	print(a, n);
	rotate(a, 4, n);

	print(a, n);
	return 0;
}

