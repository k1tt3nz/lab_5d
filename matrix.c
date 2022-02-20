#include "matrix.h"
#include <stdlib.h>
#include <malloc.h>
#include "array.h"

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

void getSum(matrix const m, int *a) {
    for (int i = 0; i < m.nRows; ++i) {
        int x = 0;
        for (int j = 0; j < m.nCols; ++j) {
            x += m.values[i][j];
        }
        a[i] = x;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int(*criteria)(matrix, int *a)) {
    int *sumRows = malloc(sizeof(int) * m.nRows);
    criteria(m, sumRows);
    for (int i = 0; i < m.nRows; ++i) {
        int minPos = i;
        for (int j = i + 1; j < m.nRows; ++j) {
            if (sumRows[j] < sumRows[minPos]) {
                minPos = j;
            }
        }
        swapRows(m, i, minPos);
        swap(&sumRows[i], &sumRows[minPos]);
    }
    free(sumRows);
}

void insertionSortRowsMatrixByColCriteria(matrix m, int(*criteria)(int *, int)) {

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
