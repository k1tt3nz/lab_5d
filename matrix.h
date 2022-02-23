#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <stdbool.h>


typedef struct matrix {
    int **values;   //Элементы матрицы
    int nRows;      //Кол-во рядов
    int nCols;      //Кол-во столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;
//Выдает сообщение при обращении к неверному индексу
//И завершает программу с кодом exit(1)
void badIndex();

//Выделяет память под структуру matrix размером nRows на nCols
matrix getMemoryMatrix(int nRows, int nCols);

//Выделяет память под массив nMatrices размером nRows на nCols
//Возвращает указатель на нулевую матрицу
matrix *getMemoryArrayOfMatrix(int nMatrices, int nRows, int nCols);

//Освобождает память выделенную под матрицу m
void freeMemoryMatrix(matrix m);

//Освобождает память выделенную под массив ms из nMatrices матриц
void freeMemoryMatrices(matrix *ms, const int nMatrices);

//Ввод матрицы m
void inputMatrix(matrix m);

//Ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, const int nMatrices);

//Вывод матрицы m
void outputMatrix(matrix const m);

//Ввод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, const int nMatrices);

void outputPosition(position const p);

//Обмен строк с номерами i1 и i2 в матрице m
void swapRows(matrix m, int t1, int t2);

//Обмен колонок с номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);


//Выполняет сортировку вставками строк матрицы m по не убыванию значения функции criteria применяемой для строк.
void selectionSortRowsMatrixByRowCriteria(matrix m, int(*criteria)(matrix, int *a));

//Выполняет сортировку вставками столбцов матрицы m по не убыванию значения функции criteria применяемой для столбцов.
void selectionSortRowsMatrixByColCriteria(matrix m, int(*criteria)(int *, int));

//Возвращает значение ’истина’, если матрица m является квадратной, иначе - 'ложь'.
bool isSquareMatrix(matrix const m);

//Возвращает значение ’истина’, если матрицы m1 и m2 равны, иначе - 'ложь'.
bool areTwoMatricesEqual(matrix m1, matrix m2);

//Возвращает значение ’истина’, если матрица m является единичной, иначе - 'ложь'.
bool isEMatrix(matrix m);

//Возвращает значение ’истина’, если матрица m является симметричной, иначе - 'ложь'.
bool isSymmetricMatrix(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//Транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m);

//Возвращает позицию первого вхождения минимального элемента матрицы m.
position getMinValuePos(matrix const m);

//Возвращает позицию первого вхождения максимального элемента матрицы m.
position getMaxValuePos(matrix const m);

//возвращает матрицу, размера nRows на nCols, построенного из элементов массива a, размещенную в динамической памяти.
matrix createMatrixFromArray(const int *a, const int nRows, const int nCols);

//сортирует ряды матрицы m по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

//возвращает матрицу, полученную перемножением матриц m1 и m2
matrix mulMatrices(matrix m1, matrix m2);

//возводит в квадрат матрицу m, если она симметрична
void getSquareOfMatrixIfSymmetric(matrix *m);

//транспонирует матрицу m, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

int getMaxDiagonalElement(matrix m, int iRows, int jCols);

//возвращает сумму максимальных элементов всех псевдодиагоналей данной матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//возвращает минимальное значение элемент матрицы m в области, образованной пирамидой выше максимального элемента
int getMinInArial(matrix m);

int getNSpecialElement(matrix m);

//заменяет предпоследнюю строку матрицы м первым из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m);



#include "matrix.c"

#endif //COURSE_MATRIX_H