#include <stdio.h>

void start_up(void) __attribute((constructor));
void clean_up(void) __attribute((destructor));

void start_up(void)
{
	printf("start_up\n");
}

int main(void)
{
	printf("In main\n");
	return 0;
}

void clean_up(void)
{
	printf("clean_up\n");
}
