#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	remove(argv[0]);
	printf("hi\n");
	return 0;
}
