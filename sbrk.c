#include <stdio.h>
#include <unistd.h>

int main(void)
{
	
	printf("break is at : %08x\n", (int*)sbrk(0));	

	printf("break is at : %08x\n", (int*)sbrk(10));	
	
	return 0;
}
