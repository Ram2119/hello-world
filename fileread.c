
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

int main ()
{
	FILE *outfile;
 
	// open file for writing
	outfile = fopen ("person.dat", "r");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit (1);
	}

	struct person output1;
	struct person output2;
		 
	// write struct to file
	fread (&output1, sizeof(struct person), 1, outfile);
	fread (&output2, sizeof(struct person), 1, outfile);
				 
	if(fwrite != 0) {
		printf("File content : \n[%d]   %s %s\n", output1.id, output1.fname, output1.lname);
		printf("[%d]   %s %s\n", output2.id, output2.fname, output2.lname);
	}
	else
		printf("error writing file !\n");
	return 0;
}	//file size will be 88 bytes
