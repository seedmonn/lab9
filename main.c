#pragma warning(disable:4996)
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]) //���������� ����������(1�� ������ ����� ���������, � ��������� ���������); C��� ��������[] ������� � ��� ����
{
	FILE* f;
	int slovo = 1, N = 0; // c���� � ����� ����������
	char ch; // ������� ������
	char ch_gag; //���������� ������
	char filename[100] = { 0 }; //��� �����

	//��������� �� ������� ���������� �� ���������
	if (argc == 2)
		strcpy(filename, argv[1]);
	else {
	tr:
		printf("Please enter a file address: ");
		gets(filename);
	}
	if ((f = fopen(filename, "r")) == NULL) //�������� ����� ��� ������
	{
		printf("Cannot open input file.\n");
		goto tr; // ���������, ���� ������������ �� ����� ��� �� ������� ������
	}

	// ������ ������������
	printf("This program deleted one word in the text file.\n");
	printf("Please enter a line to delete: ");
	scanf_s("%d", &N);
	FILE* fpout;
	fpout = fopen("C:\\Users\\Admin\\source\\repos\\laba9\\result.txt", "w"); // ����� �����
	fprintf(fpout, "Result text file: \n");
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == -1)
			break;
		if ((N != slovo) || (ch == ' ' || ch == '\t' || ch == '\n'))
		{
			fprintf(fpout, "%c", ch); // ������ �������������. �������, ��� �����
		}
		if ((ch == ' ' || ch == '\t' || ch == '\n') && ch_gag != ' ' && ch_gag != '\t' && ch_gag != '\n') // ������, ���, ����� ����� ��������� � ������ ���������� ��������
			slovo++;
		if (ch == '\n')
			slovo = 1; // �������� ����������
		ch_gag = ch; //������ ������ � ������
	}
	fclose(fpout); // ��������� ����� �������������
	fclose(f);
	return 0;
}