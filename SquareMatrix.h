#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include<stdlib.h>

using namespace std;

class SquareMatrix {
public:

    SquareMatrix(int m) : mM(m) {
        mArray = (int *) malloc(sizeof(int) * mM * mM);
        for (int i = 0; i < mM; i++) {
            for (int j = 0; j < mM; j++) {
                this->write(i,j, 0);
            }
        }
    }

    virtual ~SquareMatrix() {
        free(mArray);
    }

    int read(int, int);
    void write(int, int, int);

    void print();

    SquareMatrix* squared();

    SquareMatrix* deep_copy();

    int size() { return mM; }

protected:

    int *mArray;
    int mM;

    int index(int, int);
    int i(int);
    int j(int);
};

#endif
