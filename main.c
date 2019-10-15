#pragma warning(disable:4996)
#include <conio.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	FILE* f;
	int slovo, N;
	slovo = 1;
	char ch;
	if ((f = fopen("D:\\Text\\text1.txt", "r")) == NULL) // Путь к файлу с текстом
	{
		printf("Cannot open input file.\n");
		return 1;
	}
	printf("Please enter the N:");
	scanf_s("%d", &N);
	FILE* fpout;
	fpout = fopen("D:\\Statistic\\Creator.txt", "w"); // Путь к записи
	fprintf(fpout, "Result text file: \n");
	while (!feof(f))
	{
		ch = fgetc(f);
		if (N != slovo)
		{
			fprintf(fpout, "%c", ch); //Считает точки и переход на следущую строку.
		}
		if (ch == ' ' || ch == '\t') //Табуляцию тоже считаем.
			slovo++;
		if (ch == '\n')
			slovo = 1;
	}
	fclose(fpout);
	fclose(f);
	return 0;
}