#include <cmath>
#include <iostream>
#include <stdlib.h>
#include "SquareMatrix.h"

int v = 5;

using namespace std;

int main()
{
    SquareMatrix *M, *M2;
    M = new SquareMatrix(v); 
    M2 = M->squared();

    M->print();
    M2->print();
    
    return 0;
}

