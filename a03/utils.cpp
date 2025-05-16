#include "utils.hpp"

#include <iostream>

bool isPermutation(int* perm, int count) {
    int *valid = new int[count]{};
    for (int i = 0; i < count; i++) {
        if (perm[i] < 0 || perm[i] >= count) {
            printf("Provided integer '%d' is out of bounds as an index for the double array!\n", perm[i]);
            delete[] valid;
            return false;
        }
        if (valid[perm[i]] == 0) {
            valid[perm[i]] = 1;
            continue;
        }
        printf("Index '%d' appears more than once which is invalid!\n", perm[i]);
        delete[] valid;
        return false;
    }
    delete[] valid;
    return true;
}

bool isSorted(double* data, int dataCount, int *perm) {
    for (int i = 1; i < dataCount; i++) if (data[perm[i - 1]] > data[perm[i]]) return false;
    return true;
}