
// C program for writing 
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to read and write
struct person 
{
	int id;
	char fname[20];
	char lname[20];
};


#if 0
int main ()
{
	FILE *outfile;
 
	// open file for writing
	outfile = fopen ("person.dat", "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit (1);
	}

	struct person input1 = {1, "rohan", "sharma"};
	struct person input2 = {2, "mahendra", "dhoni"};
		 
	// write struct to file
	fwrite (&input1, sizeof(struct person), 1, outfile);
	fwrite (&input2, sizeof(struct person), 1, outfile);
				 
	if(fwrite != 0) 
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	return 0;
}
#endif


int main ()
{
	FILE *outfile;
 
	// open file for writing
	outfile = fopen ("test.dat", "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit (1);
	}

	int a[] = {1, 2, 3};
	char b[] = "i am at the edge";

	// write struct to file
	//fwrite (&input1, sizeof(struct person), 1, outfile);
	//fwrite (&input2, sizeof(struct person), 1, outfile);
		
	fputs(b, outfile);
	int i;
	for (i=0; i<sizeof(a)/sizeof(a[0]); i++)
		fprintf(outfile, "%d", a[i]);

	if(fwrite != 0) 
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	return 0;
}
