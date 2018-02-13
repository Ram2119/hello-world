
// Sample program to show that memcpy() can loose data.
#include <stdio.h>
#include <string.h>

#if 1

void myMemCpy(void *dest, void *src, size_t n)
{
	// Typecast src and dest addresses to (char *)
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	
	// Copy contents of src[] to dest[]
	int i;
	int len = strlen(csrc)+1;
//	if ((cdest+(len/2)) < (csrc+(len/2))) {
		for (i=0; i<n; i++) {
			cdest[i] = csrc[i];
			printf("## %d  ", csrc[i]);	
		}
		printf("\n");
/*	}
	else {
		for (i=n; i>=0; i--)
			cdest[i] = csrc[i];
	}*/
}


int main()
{
	char csrc[100] = "Geeksfor";
	//memcpy(csrc+5, csrc, strlen(csrc)+1);
	myMemCpy(csrc, csrc+5, strlen(csrc)+1);
	printf("%s\n", csrc);
	
	return 0;
}
#endif

#if 0
// Sample program to show that memmove() is better than memcpy()
// when addresses overlap.
int main()
{
	char csrc[100] = "Geeksfor";
	memmove(csrc+5, csrc, strlen(csrc)+1);
	printf("%s\n", csrc);
	
	return 0;
}
#endif
