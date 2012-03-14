#include <cmath>
#include <iostream>
#include <stdlib.h>
#include "Graph.h"
#include "SquareMatrix.h"

int v = 5;

using namespace std;

int main()
{
    cout << "about to new Graph(v)" << endl;

    Graph *G;
    G = new Graph(v);

    cout << "about to new Graph(new SquareMatrix(v))" << endl;

    Graph *G2;
    G2 = new Graph(new SquareMatrix(v));

    cout << " about to new Graph('3arm222star') " << endl;

    Graph *G3;
    G3 = new Graph("3arm222star");

    return 0;
}

