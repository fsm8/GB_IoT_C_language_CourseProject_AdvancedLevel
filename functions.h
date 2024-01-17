
typedef float(*function)(float); // переменная - указатель на функцию

/// Вычисление корней уравнения линейным поиском (rootFindLineSearch)
float root(float xl, float xr, float eps1, int* stepcount, function f, function f2);

/// Вычисление интеграла методом прямоугольника (calcIntegralSquare)
float integral(float xl, float xr, int eps2, function f);

float f1(float x); // функция 1
float f2(float x); // функция 2
float f3(float x); // функция 3

/// Парсим опции командной строки
void cmd(int argc, char* argv[], int* a, int* b, int* c, float* eps1);

/// Печать (если соответствующие флаги командной строки = 1) абсцисс точек пересечения кривых и число итераций, потребовавшихся на приближённое решение уравнений при поиске точек пересечения
void printing(int a, int b, float point, int stepcount, char strP);