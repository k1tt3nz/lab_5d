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

    sortRowsByMaxElement(m1);

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

void test_exercise4_one() {
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

void test() {
    test_exercise1();
    test_exercise2();
    test_exercise4_one();
    test_exercise4_NoSymmetric();
}

int main() {
    test();
    return 0;
}