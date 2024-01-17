
typedef float(*function)(float); // ���������� - ��������� �� �������

/// ���������� ������ ��������� �������� ������� (rootFindLineSearch)
float root(float xl, float xr, float eps1, int* stepcount, function f, function f2);

/// ���������� ��������� ������� �������������� (calcIntegralSquare)
float integral(float xl, float xr, int eps2, function f);

float f1(float x); // ������� 1
float f2(float x); // ������� 2
float f3(float x); // ������� 3

/// ������ ����� ��������� ������
void cmd(int argc, char* argv[], int* a, int* b, int* c, float* eps1);

/// ������ (���� ��������������� ����� ��������� ������ = 1) ������� ����� ����������� ������ � ����� ��������, ��������������� �� ����������� ������� ��������� ��� ������ ����� �����������
void printing(int a, int b, float point, int stepcount, char strP);