#include "matrix.h"

void exercise1() {
    matrix m = getMemoryMatrix(3, 3);
    inputMatrix(m);

    position posMin = getMinValuePos(m);
    position posMax = getMaxValuePos(m);
    swapRows(m, posMin.rowIndex, posMax.rowIndex);
}

void exercise2() {
    matrix m = getMemoryMatrix(3, 3);
    inputMatrix(m);

    insertionSortRowsMatrixByRowCriteria(m,getSum);
    outputMatrix(m);
}

int main() {
    exercise2();

    return 0;
}
