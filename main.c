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

void test_exercise6_reciprocal() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, -5,
                    1, -2
            },
            2, 2
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, -9,
                    -1, 5
            },
            2, 2
    );

    assert(isMutuallyInverseMatrices(m1, m2) == 1);

}

void test_exercise6_notReciprocal() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, -5,
                    1, -2
            },
            2, 2
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, -9,
                    -1, 5
            },
            2, 2
    );

    assert(isMutuallyInverseMatrices(m1, m2) == 1);

}

void test_exercise7() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
}

void test_exercise8_MaxInTheMiddle() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            },
            3, 4
    );

    assert(getMinInArea(m1) == 5);

    freeMemoryMatrix(m1);
}

void test_exercise8_MaxOnTheLeftEdge() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    12, 1, 1, 2
            },
            3, 4
    );

    assert(getMinInArea(m1) == 3);

    freeMemoryMatrix(m1);
}


void test_exercise8_MaxInTheFirstRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 7, 12, 6,
                    3, 11, 8, 9,
                    2, 1, 1, 2
            },
            3, 4
    );

    assert(getMinInArea(m1) == 12);

    freeMemoryMatrix(m1);
}

/*void test_exercise11() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4
    );

    getNSpecialElement(m);
}*/

void test_exercise12_severalIdenticalMinimum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            },
            3, 3
    );

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise12_minInTheLastColumn() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 6, 4,
                    4, 5, 6, 5,
                    7, 8, 2, 0,
                    9, 3, 1, 1
            },
            4, 4
    );

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 6, 4,
                    4, 5, 6, 5,
                    4, 5, 0, 1,
                    9, 3, 1, 1
            },
            4, 4
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemoryMatrix(m1);
    freeMemoryMatrix(m2);
}

void test_exercise12_size2x2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2,
                    1, 1
            },
            2, 2
    );

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 1,
                    1, 1
            },
            2, 2
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
    test_exercise6_reciprocal();
    test_exercise6_notReciprocal();
    test_exercise7();
    test_exercise8_MaxInTheFirstRow();
    test_exercise8_MaxInTheMiddle();
    test_exercise8_MaxOnTheLeftEdge();
    test_exercise12_minInTheLastColumn();
    test_exercise12_severalIdenticalMinimum();
    test_exercise12_size2x2();
}


int main() {
    test();
    return 0;
}