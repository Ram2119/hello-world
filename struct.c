
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#if 0
int main(void)
{
	struct node {
/*		int a;
		char c;
		int b;
*/
		char b;
		double c;
		int d;
	};

	printf("size : %d\n", sizeof(struct node));

	return 0;
}
#endif


#if 0
union un{
	char a;
	int b;
	//float c;
	//double d;
	short e;
}u;

int main ( void )
{
		printf( " %d\n", sizeof( u ));
		//u.b = 0xffffffff;
		u.a = 0xb0;
		printf ( "%x\n",u.a);
		printf ( "%x\n",u.b);
		printf ( "%x\n",u.e);
		
		
		return 0;
}
#endif


#if 0
struct test
{
	char *str;
};
 
int main()
{
	struct test st1, st2;
	
	st1.str = (char*)malloc(20);
	strcpy(st1.str, "GeeksforGeeks");
	
	st2 = st1;
	
	st1.str[0] = 'X';
	st1.str[1] = 'Y';
					 
	/* Since copy was shallow, both strings are same */
	printf("st1's str = %s\n", st1.str);
	printf("st2's str = %s\n", st2.str);
				 
	return 0;
}
#endif


struct A {
	int a;
	double d;
	char c;
};

int main(void)
{
	printf("c is at %d\n", offsetof(struct A, c));

	return 0;
}
