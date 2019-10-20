#pragma warning(disable:4996)
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]) //количество аргументов(1ый всегда адрес экзешника, в остальных параметры); Cами праметры[] которые у нас есть
{
	FILE* f;
	int slovo = 1, N = 0; // cлова и номер удаляемого
	char ch; // Текущий символ
	char ch_gag; //предыдущий символ
	char filename[100] = { 0 }; //имя файла

	//Проверяем на наличие аргументов по умолчанию
	if (argc == 2)
		strcpy(filename, argv[1]);
	else {
	tr:
		printf("Please enter a file address: ");
		gets(filename);
	}
	if ((f = fopen(filename, "r")) == NULL) //Открытие файла для чтения
	{
		printf("Cannot open input file.\n");
		goto tr; // Повторяем, пока пользователь не умрет или не захочет выпить
	}

	// Слоган МакДональдса
	printf("This program deleted one word in the text file.\n");
	printf("Please enter a line to delete: ");
	scanf_s("%d", &N);
	FILE* fpout;
	fpout = fopen("C:\\Users\\Admin\\source\\repos\\laba9\\result.txt", "w"); // Умное чтиво
	fprintf(fpout, "Result text file: \n");
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == -1)
			break;
		if ((N != slovo) || (ch == ' ' || ch == '\t' || ch == '\n'))
		{
			fprintf(fpout, "%c", ch); // Работу программистам. Выводим, что хотим
		}
		if ((ch == ' ' || ch == '\t' || ch == '\n') && ch_gag != ' ' && ch_gag != '\t' && ch_gag != '\n') // Делаем, так, чтобы слова считались с учетом нескольких пробелов
			slovo++;
		if (ch == '\n')
			slovo = 1; // позовите следующего
		ch_gag = ch; //ничего общего с кляпом
	}
	fclose(fpout); // закрываем после проветривания
	fclose(f);
	return 0;
}