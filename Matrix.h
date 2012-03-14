#ifndef MATRIX_H
#define MATRIX_H

#include<stdlib.h>

using namespace std;

class Matrix {
public:

    Matrix(int m, int n) : mM(m), mN(n) {
        mArray = (int *) malloc(sizeof(int) * mM * mN);
    }

    virtual ~Matrix() {
        free(mArray);
    }

    int index(int, int);
    int i(int);
    int j(int);

protected:

    int *mArray;
    int mM, mN;

};

#endif
