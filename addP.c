#include <stdio.h>

int main(void)
{
	int sum = printf("%*c%*c", 4, '\r', 5, '\r');
	
	printf("sum : %d\n", sum);

	
	int n = 12345;
	printf("n : %10d\n", n);


//	printf("My mobile number is 7\a8\a7\a3\a9\a2\a3\a4\a0\a8\a");

	char *s = "globaledge";
//	s[0] = 'b';

	printf("s : %s\n", s);
	printf("sizeof(s) : %lu\n", sizeof(s));
	printf("add(s) : %p\n", s);

	for(sum=0; n>0; sum+=n%10, n/=10);
	printf("digitz sum : %d\n", sum);	
	return 0;
}
