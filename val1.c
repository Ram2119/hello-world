#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s = malloc(10);

	s[50] = 'a';
	s[40] = 'a';

	//free(s);
	//free(s);

	int a;
	if (a > 0)
		printf("hi\n");
	return 0;
}
