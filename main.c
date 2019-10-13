#pragma warning(disable:4996)
#include <stdio.h>
#define MAXLINE 1024

int main(void)
{
	FILE* fpin;
	FILE* fpout;

	char line[MAXLINE];
	char* ptr;
	int N = 0;

	fpin = fopen("text.txt", "rt");
	if (fpin == NULL)
		return;
	fpout = fopen("result.txt", "wt");
	if (fpout == NULL)
		return;
	printf("Enter N: \n");
	while (!feof(fpin))
	{
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break;

		while ()
		{
			
		}
		fputs(line, fpout);
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}
