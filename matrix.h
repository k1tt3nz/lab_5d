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

void freeMemoryMatrices(matrix *ms, const int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, const int nMatrices);

void outputMatrix(matrix const m);

void outputMatrices(matrix *ms, const int nMatrices);

void outputPosition(position const p);

void swapRows(matrix m, int t1, int t2);

void swapColumns(matrix m, int j1, int j2);

void getSum(matrix const m, int *a);

void insertionSortRowsMatrixByRowCriteria(matrix m, int(*criteria)(matrix, int *a));

void insertionSortRowsMatrixByColCriteria(matrix m, int(*criteria)(int *, int));

bool isSquareMatrix(matrix const m);

bool areTwoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix const m);

position getMaxValuePos(matrix const m);

matrix createMatrixFromArray(const int *a, const int nRows, const int nCols);

#include "matrix.c"

#endif //COURSE_MATRIX_H
