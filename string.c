#include <stdio.h>
#include <stdlib.h>

#if 0
void swap(char *str1, char *str2)
{
	char *temp = str1;
	str1 = str2;
	str2 = temp;
}  
  
int main()
{
	char *str1 = "geeks";
	char *str2 = "forgeeks";
	swap(str1, str2);
	printf("str1 is %s, str2 is %s", str1, str2);
	getchar();
	
	return 0;
}
#endif


#if 0
int main()
{
/*	char *str; 
	str = "GfG";     // Stored in read only part of data segment 
	*(str+1) = 'n'; // Problem:  trying to modify read only memory 
*/
	char s[] = "GfG";
	*(s + 1) = 'n';
	getchar();
	
	return 0;
}
#endif


#if 1
char *getString()
{
	//char str[] = "GfG";	
	char *str = "GfG"; /* Stored in read only part of shared segment */	
	/* No problem: remains at address str after getString() returns*/
	return str;  
}     
 
int main()
{
	printf("%s", getString());  
	getchar();
	return 0;
}
#endif


#if 0
char *getString()
{
	int size = 4;
	char *str = (char *)malloc(sizeof(char)*size); /*Stored in heap segment*/
	*(str+0) = 'G'; 
	*(str+1) = 'f';  
	*(str+2) = 'G';
	*(str+3) = '\0';  
	
	/* No problem: string remains at str after getString() returns */   
	return str;  
}     
int main()
{
	char *s = getString();	
	printf("%s", s);  
	getchar();
	free(s);
	return 0;
}
#endif

