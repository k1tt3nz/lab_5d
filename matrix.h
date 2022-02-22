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


void getSum(matrix const m, int *a);

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

//Транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m);

//Возвращает позицию первого вхождения минимального элемента матрицы m.
position getMinValuePos(matrix const m);

//Возвращает позицию первого вхождения максимального элемента матрицы m.
position getMaxValuePos(matrix const m);

//возвращает матрицу, размера nRows на nCols, построенного из элементов массива a, размещенную в динамической памяти.
matrix createMatrixFromArray(const int *a, const int nRows, const int nCols);

void sortRowsByMaxElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

#include "matrix.c"

#endif //COURSE_MATRIX_H