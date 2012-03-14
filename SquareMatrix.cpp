#include <stdlib.h>
#include <iostream>
#include "SquareMatrix.h"

using namespace std;

class SquareMatrix;

/* 2D matrices are stored as 1D arrays
   store the (i, j)th entry of an m x n matrix at index (i*n + j)
   index = i*n + j
   i = index / n
   j = index % n
   for adjacency matrices m = n = v
*/

int SquareMatrix::index(int i, int j) { return i * mM + j; }

int SquareMatrix::i(int index) { return index/mM; }

int SquareMatrix::j(int index) { return index % mM;}

int SquareMatrix::read(int i, int j) { return mArray[index(i,j)]; }

void SquareMatrix::write(int i, int j, int val) { mArray[index(i,j)] = val; }

SquareMatrix* SquareMatrix::squared() {
    SquareMatrix* product = new SquareMatrix(mM);
    int sum = 0;
    for (int i = 0; i < mM; i++) {
        for (int j = 0; j < mM; j++) {
            sum = 0;
            for (int k = 0; k < mM; k++) {
                sum += this->read(i,j) * this->read(k,j);
            }
            product->write(i,j, sum);
        }
    }
    return product;
}

void SquareMatrix::print() {
    cout << "matrix " << mM << " by " << mM << endl;
    for (int i = 0; i < mM; i++) {
        for (int j = 0; j < mM; j++) {
            cout << read(i,j);
        }
        cout << endl;
    }
    cout << "end of matrix" << endl;
}

SquareMatrix* SquareMatrix::deep_copy() {
    SquareMatrix* copy = new SquareMatrix(mM);
    for (int i = 0; i < mM; i++) {
        for (int j = 0; j < mM; j++) {
            copy->write( i, j, this->read(i,j) );
        }
    }
}
