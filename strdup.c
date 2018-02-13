#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *s = "globaledge";


	char *p = strdup(s);
	printf("p : %s\n", p);	

	free(p);
	p = NULL;
	return 0;
}
