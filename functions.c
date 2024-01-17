#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

float f1(float x) // ������� 1
{
	return (0.6 * x) + 3;
}

float f2(float x) // ������� 2
{
	return pow((x - 2), 3) - 1;
}

float f3(float x) // ������� 3
{
	return 3 / x;
}

/// ����� ��������� ������
void cmd(int argc, char* argv[], int* a, int* b, int* c, float* eps1)
{
	for (int i = 0; i < argc; i++) // ��������� ����� ��������� ������
	{
		if (strcmp(argv[i], "-help") == 0) // ���� ������ ���� -help
		{
			printf("���������� ���������� ��� ������� ������� ������, ������������ ������� ���� �������.\n\n");

			printf("������ ���������� � ��� �����:\n");
			printf("�) ������ ����� ����������� ������� � ������������� ������� ��� �������,\n");
			printf("�) ������ ������� ������, ������������ ������� ���� �������.\n\n");

			printf("������ �������������� ���������� ������:\n");
			printf("1. -help - ������ ������, ������� ������������ ������ ���������� � �� ����������.\n");
			printf("2. -a - ���������� �������� ����� ����������� ������.\n");
			printf("3. -iter - ���������� ����� ��������, ��������������� �� ����������� ������� ��������� ��� ������ ����� �����������.\n");
			printf("4. -sqr - ���������� ������� ����� ��� ������� ������� f1, f2, f3.\n");
			printf("5. -eps1 - ���� �������� (� ������� 0,001) ��� ������ ����� �����������. �������� 100 ����. ��-��������� eps1 = 0,001\n");
		}

		if (strcmp(argv[i], "-a") == 0)
		{
			*a = 1; // ������ ���� �� ����� ��������� ������ �� ������ ������� ����� ����������� ������
		}

		if (strcmp(argv[i], "-iter") == 0)
		{
			*b = 1; // ������ ���� �� ����� ��������� ������ �� ������ ����� ��������
		}

		if (strcmp(argv[i], "-sqr") == 0)
		{
			*c = 1; // ������ ���� �� ����� ��������� ������ �� ������ �������� ����� ��� ������� ������� f1, f2, f3
		}

		if (strcmp(argv[i], "-eps1") == 0)
		{
			// ������ �� ������� ��������� ��� ���������� �������� �������� ����� �����
			char s[102] = { 0 }; // ������ � ������� �������� �������� ����� �����
			int brk = 0; // ���������� ��� �������� �����

			if (i != argc - 1) // ���� ���� �� �������� ��������� � ������ ����������
			{
				strncpy(s, argv[i + 1], 100); // �������� �������� ����� ����� ��� ��� ��������

				if (s[0] >= '0' && s[0] <= '9') // �������� �� ������� �������� ����� �����. ������
				{
					printf("\n�� ����� eps1: %f\n", strtof(argv[i + 1], NULL)); // ����� �� ����� ��������� �����
					if (strtof(argv[i + 1], NULL)) // ���� � ����� �����, � strtof ��������� �� float �� �����, �� �� ���� ������ � ������ ����
					{
						*eps1 = strtof(argv[i + 1], NULL); // ����������� ������ � �������� ���� float
					}
				}
				else  // �������� �� ������� �������� ����� �����. ����
				{
					printf("\n�� �� ����� ����� ��� ������ �������!\n");
					continue;
				}
			}
			else // ���� �������� ��������� � ������ ����������
			{
				printf("\n�� �� ����� ����� ��� ������ �������!\n");
			}
		}
	}
}

/// ���������� ������ ��������� �������� ������� (rootFindLineSearch)
float root(float xl, float xr, float eps1, int* stepcount, function f, function f2)
{
	float x, minx = xl, nextstep;
	nextstep = fabs(xr - xl) / (10 / eps1); //��������� �������� �� ������� 
	*stepcount = 0;
	for (x = xl; x < xr; x += nextstep, (*stepcount)++)
	{

		if ((fabs(f(x)) - (fabs(f2(x)))) <= eps1)
		{
			minx = x;
		}
	}
	return minx;
}

/// ���������� ��������� ������� �������������� (calcIntegralSquare)
float integral(float xl, float xr, int eps2, function f)
{
	float sum = 0;
	float h = (xr - xl) / eps2; // ������ ���������� �������, ��� ��� ��������������
	for (int i = 0; i < eps2; i++)
	{
		sum = sum + f(xl); // ���������� �������� ����� ������������� ������
		xl += h;
	}
	return sum * h; // �������� ����� ������� ����� ������������� ������ �� ������ ���������� �������
}

/// ������ ������� ����� ����������� ������ � ����� ��������, ��������������� �� ����������� ������� ��������� ��� ������ ����� �����������
void printing(int a, int b, float point, int stepcount, char strP)
{
	if (a) // ���� ���������� ���� �� ����� ��������� ������ �� ������ �������� ����� ����������� ������, �� �������� ��
	{
		if (strP == 'C')
		{
			printf("\n");
			printf("________________���������� �������__________________\n");
			printf("�������� ����� ����������� ������:\n");
		}
		printf("����� %c = %f ", strP, point); // �������� ����� ����������� ������ ������� � ������������� ������� ��� �������
		if (!b)
		{
			printf("\n");
		}
	}
	if (b) // ���� ���������� ���� �� ����� ��������� ������ �� ������ ����� ��������, �� �������� ��
	{
		printf("������ ������ �� %d �������� \n", stepcount);
	}
}