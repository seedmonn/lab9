#pragma warning(disable:4996)
#include <conio.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	FILE* f;
	int slovo, N;
	slovo = 1;
	char ch;
	char ch_gag;
	if ((f = fopen("C:\\Users\\Admin\\source\\repos\\laba9\\text.txt", "r")) == NULL) // Путь к файлу с текстом
	{
		printf("Cannot open input file.\n");
		return 1;
	}
	printf("Please enter the N:");
	scanf_s("%d", &N);
	FILE* fpout;
	fpout = fopen("C:\\Users\\Admin\\source\\repos\\laba9\\result.txt", "w"); // Путь к записи
	fprintf(fpout, "Result text file: \n");
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == -1)
			break;
		if ((N != slovo) || (ch == ' ' || ch == '\t' || ch == '\n'))
		{
			fprintf(fpout, "%c", ch); //Считает точки и переход на следущую строку.
		}
		if ((ch == ' ' || ch == '\t' || ch == '\n') && (ch_gag != ' ' || ch_gag != '\t' || ch_gag != '\n')) //Табуляцию тоже считаем.
			slovo++; 
		if (ch == '\n')
			slovo = 1;
		ch_gag = ch;
	}
	fclose(fpout);
	fclose(f);
	return 0;
}