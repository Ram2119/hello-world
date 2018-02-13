#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int *ptr = a;

//	printf("# : %d\n", *ptr);	//1
//	++*ptr;
//	printf("## : %d\n", *ptr);	//2
	*ptr++;						
	printf("### : %d\n", *ptr);	//2
	*++ptr;						
	printf("#### : %d\n", *ptr);	//3

	return 0;
}
