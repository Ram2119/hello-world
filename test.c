#include <stdio.h>
#define  MUL(a,b)  a*b
#define  CONC(a, b)  a##b	
#define  STR(x)	#x


int add(int a, int b)
{
	return a+b;
}

int main(void)
{
	int a = 10;
	int b = 20;

	int c = add(a, b);
							
	printf("res : %d\n", c);

	printf("a*b : %d\n", MUL(a,b)); 
	
//	printf("conc(a,b) :  %d\n", CONC(a,b));
	printf("conc(a,b) :  %d\n", CONC(10, 20));

	printf("str(a) : %s\n", STR(a));

	printf("__FILE__ : %s\n", __FILE__);
	printf("__DATE__ : %s\n", __DATE__);
	printf("__LINE__ : %d\n", __LINE__);
		
	return 0;
}

