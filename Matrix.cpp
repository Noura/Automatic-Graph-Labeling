#include <stdlib.h>
#include "SquareMatrix.h"

using namespace std;

class SquareMatrix;

SquareMatrix* SquareMatrix::squared() {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum = 0;
            for (int k = 0; k < m; k++) {
                sum += matrix[SquareMatrix::index(i,k)]*matrix[SquareMatrix::index(k,j)];
            }
            matrix2[SquareMatrix::index(i,j)] = sum;
        }
    }
}

/* 2D matrices are stored as 1D arrays
   store the (i, j)th entry of an m x n matrix at index i*n + j
   index = i*n + j
   i = index / n
   j = index % n
   for adjacency matrices m = n = v
*/

int SquareMatrix::index(int i, int j) { return i * mV + j; }

int SquareMatrix::i(int index) { return index/mV; }

int SquareMatrix::j(int index) { return index % mV;}
