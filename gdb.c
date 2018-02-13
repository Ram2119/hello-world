#include <stdio.h>

int main(void)
{
	char *p = "abc";

	while (1)
		printf("going to generate...[%d]\n", getpid());	
	//*p = 'd';

	printf("## %s\n", p);
	return 0;
}
