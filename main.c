#include "matrix.h"

void exercise1() {
    matrix m = getMemoryMatrix(3, 3);
    inputMatrix(m);

    position posMin = getMinValuePos(m);
    position posMax = getMaxValuePos(m);
    swapRows(m, posMin.rowIndex, posMax.rowIndex);
}

int main() {
    exercise1();

    return 0;
}
