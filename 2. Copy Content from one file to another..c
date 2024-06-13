#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fptr1, *fptr2;
	char c;
	fptr1 = fopen("File2.txt", "r");
	if (fptr1 == NULL)
	{
		printf("Cannot open file 1\n");
		exit(0);
	}
	fptr2 = fopen("File3.txt", "w");
	if (fptr2 == NULL)
	{
		printf("Cannot open file 2\n");
		exit(0);
	}
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	printf("\nContents copied from file 1 to file 2");
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}