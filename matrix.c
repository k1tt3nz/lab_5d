#include "matrix.h"

#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#include "array.h"

void impossibleMultiplication() {
    fprintf(stderr, "multiplication isn't possible");
    exit(1);
}

void badIndex() {
    fprintf(stderr, "bad index\n");
    exit(1);
}

void swapVoid(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;

    for (size_t i = 0; i < size; ++i) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;

        pa++;
        pb++;
    }
}

matrix getMemoryMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemoryArrayOfMatrix(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; ++i) {
        ms[i] = getMemoryMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemoryMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        free(m.values);
    }

    free(m.values);
}

void freeMemoryMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemoryMatrix(ms[i]);
    }

    free(ms->values);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix const m) {
    for (int i = 0; i < m.nRows; ++i) {
        printf("{");

        for (int j = 0; j < m.nCols; ++j) {
            printf("%d ", m.values[i][j]);
        }
        printf("\b}\n");
    }
}

void outputMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

void outputPosition(position const p) {
    printf("%d %d", p.rowIndex, p.colIndex);
}

void swapRows(matrix m, const int i1, const int i2) {
    if (i1 >= m.nRows || i2 >= m.nRows)
        badIndex();

    swapVoid(&m.values[i1], &m.values[i2], sizeof(int));
}

void swapColumns(matrix m, int j1, int j2) {
    if (j1 >= m.nCols || j2 >= m.nCols) {
        badIndex();
    }

    for (int i = 0; i < m.nRows; ++i) {
        swapVoid(&m.values[i][j1], &m.values[i][j2], sizeof(int));
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nRows);
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 0; i < m.nRows - 1; ++i)
        for (size_t j = i + 1; j < m.nRows; ++j)
            if (criteriaArray[i] > criteriaArray[j]) {
                swapRows(m, i, j);
                swapVoid(&criteriaArray[i], &criteriaArray[j], sizeof(int));
            }

    free(criteriaArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *colsElements = (int *) malloc(sizeof(int) * m.nRows);
    for (size_t j = 0; j < m.nCols; ++j) {
        for (size_t i = 0; i < m.nRows; ++i)
            colsElements[i] = m.values[i][j];

        criteriaArray[j] = criteria(colsElements, m.nRows);
    }

    for (size_t i = 0; i < m.nCols - 1; ++i)
        for (size_t j = i + 1; j < m.nCols; ++j)
            if (criteriaArray[i] > criteriaArray[j]) {
                swapColumns(m, i, j);
                swapVoid(&criteriaArray[i], &criteriaArray[j], sizeof(int));
            }

    free(criteriaArray);
    free(colsElements);
}


bool isSquareMatrix(matrix const m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        return false;
    }

    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m1.nCols; ++j) {
            if (m1.values[i][j] != m2.values[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        return false;
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if ((i == j && m.values[i][j] != 1) || (i != j && m.values[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] != m.values[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool twoMatricesEqual(matrix const m1, matrix const m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (size_t i = 0; i < m1.nRows; ++i)
        for (size_t j = 0; j < m1.nCols; ++j)
            if (m1.values[i][j] != m2.values[i][j])
                return false;

    return true;
}

bool isMutuallyInverseMatrices(matrix const m1, matrix const m2) {
    matrix m3 = mulMatrices(m1, m2);
    bool result = isEMatrix(m3);

    freeMemoryMatrix(m3);

    return result;
}

void transposeSquareMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = i + 1; j < m.nCols; ++j)
            swapVoid(&m.values[i][j], &m.values[j][i], sizeof(int));
}

position getMinValuePos(matrix const m) {
    position minPos = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] < m.values[minPos.rowIndex][minPos.colIndex]) {
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }
        }
    }
    return minPos;
}

position getMaxValuePos(matrix const m) {
    position maxPos = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] > m.values[maxPos.rowIndex][maxPos.colIndex]) {
                maxPos.rowIndex = i;
                maxPos.colIndex = j;
            }
        }
    }
    return maxPos;
}

matrix createMatrixFromArray(const int *a, const int nRows, const int nCols) {

    matrix m = getMemoryMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            m.values[i][j] = a[k++];
        }
    }
    return m;
}

void sortRowsByMaxElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByMinElement() {

}

matrix mulMatrices(matrix const m1, matrix const m2) {
    if (m1.nCols != m2.nRows)
        impossibleMultiplication();

    matrix m3 = getMemoryMatrix(m1.nRows, m2.nCols);
    for (size_t i = 0; i < m1.nRows; ++i)
        for (size_t j = 0; j < m2.nCols; ++j) {
            m3.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; ++k)
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int criteriaArray[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = getSum(m.values[i], m.nCols);
    }

    if (isUnique(criteriaArray, m.nRows)) {
        transposeSquareMatrix(m);
    }
}

int getMaxDiagonalElement(matrix m, int iRows, int jCols) {
    int maxElement = 0;
    while (iRows < m.nRows && jCols < m.nCols) {
        maxElement = max2(maxElement, m.values[iRows++][jCols++]);
    }
    return maxElement;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sumElements = 0;
    for (int i = 1; i < m.nRows; ++i) {
        sumElements += getMaxDiagonalElement(m, i, 0);
    }

    for (int j = 1; j < m.nCols; ++j) {
        sumElements += getMaxDiagonalElement(m, 0, j);
    }

    return sumElements;
}

int getMinInArea(matrix const m) {
    position leftElement = getMaxValuePos(m);
    position rightElement = leftElement;

    int minElement = m.values[leftElement.rowIndex][leftElement.colIndex];
    if (leftElement.rowIndex == 0)
        return minElement;

    int subArr[10];
    int sizeSubArr = 1;
    while (leftElement.rowIndex >= 0 && rightElement.rowIndex <= m.nCols) {
        if (leftElement.colIndex == -1) {
            leftElement.colIndex++;
            sizeSubArr--;
        }

        if (rightElement.colIndex == m.nCols) {
            rightElement.colIndex--;
            sizeSubArr--;
        }

        int i = 0;
        while (i < sizeSubArr) {
            subArr[i] = (m).values[leftElement.rowIndex][leftElement.colIndex + i];
            i++;
        }

        minElement = getMin(subArr, sizeSubArr);

        rightElement.rowIndex--;
        rightElement.colIndex++;
        leftElement.rowIndex--;
        leftElement.colIndex--;
        sizeSubArr += 2;
    }

    return minElement;
}

int getNSpecialElement(matrix m) {
    long long criteriaArray[m.nCols];
    int *subArray = (int *) calloc(m.nRows, sizeof(int));
    int *maxArray = (int *) calloc(m.nRows, sizeof(int));
    for (int jCols = 0; jCols < m.nCols; ++jCols) {
        for (int iRows = 0; iRows < m.nRows; ++iRows) {
            subArray[iRows] = m.values[iRows][jCols];
            maxArray[jCols] = max2(maxArray[jCols], m.values[iRows][jCols]);
        }

        criteriaArray[jCols] = getSum(subArray, m.nRows);
    }
    outputArray(criteriaArray,m.nCols);
    outputArray(maxArray,m.nRows);
    /*int counterSpecialElement = 0;
    for (int jCols = 0; jCols < m.nCols; ++jCols) {
        for (int iRows = 0; iRows < m.nRows; ++iRows) {
            if (criteriaArray[jCols] - m.values[iRows][jCols] < criteriaArray[jCols]) {
                counterSpecialElement++;
                printf("%d ", counterSpecialElement);
            }
        }
    }

    return counterSpecialElement;*/
}

