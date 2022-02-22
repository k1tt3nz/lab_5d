#include "matrix.h"
#include "array.h"

#include <assert.h>

void test_exercise1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    2, 2, 2,
                    3, 3, 3
            },
            3, 3
    );

    position minIndex = getMinValuePos(m1);
    position maxIndex = getMaxValuePos(m1);
    swapRows(m1, minIndex.rowIndex, maxIndex.rowIndex);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    2, 2, 2,
                    1, 1, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3
    );

//    sortRowsByMaxElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2));
    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise3() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 2,
                    3, 2, 1
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    14, 10, 10,
                    10, 9, 10,
                    10, 10, 14
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise4_one() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6
    );

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            },
            3, 6
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise4_NoSymmetric() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 3,
                    5, 5, 1,
                    2, 1, 2
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    assert(isSymmetricMatrix(m1) == 0);

    freeMemoryMatrix(m1);
}

void test_exercise5_Unique() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    2, 2, 2,
                    3, 3, 3
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 2, 3,
                    1, 2, 3
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise5_NotUnique() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 1, 2,
                    2, 3, 2,
                    3, 3, 3
            },
            3, 3
    );

    //Матрица не будет транспонирована
    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 1, 2,
                    2, 3, 2,
                    3, 3, 3
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test() {
    test_exercise1();
    test_exercise2();
    test_exercise3();
    test_exercise4_one();
    test_exercise4_NoSymmetric();
    test_exercise5_Unique();
    test_exercise5_NotUnique();
}

int main() {
    test();
    return 0;
}