#include <cmath>
#include <iostream>
#include <stdlib.h>


using namespace std;

void print_matrix(int** matrix, int m, int n) {
    cout << "matrix " << m << " by " << n << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << "end of matrix" << endl;
}

int main()
{
/*    const int size = 50;
    double sinTable[size][size];

    #pragma omp parallel for num_threads( 5 )
    for(int n=0; n<size; ++n) {
        sinTable[n][n] = std::sin(2 * M_PI *n/size);
        cout << "n = " << n << "\n";
    }*/

    int v = 10;
//    int Adj[v][v], Path2[v][v];
    int **Adj, **Path2;
    Adj = (int **) malloc(sizeof(int) * v * v);
    Path2 = (int **) malloc(sizeof(int) * v * v);

    cout << "variables initialized" << endl;

    int sum;

    // initialize matrices
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            Adj[i][j] = (i + j) % 2;
            Path2[i][j] = 0;
        }
    }

    cout << "matrices initialized" << endl;

    // multiply matrices!
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            sum = 0;
            for (int k = 0; k < v; k++) {
                sum += Adj[i][k]*Adj[k][j];
            }
            Path2[i][j] = sum;
        }
    }

    cout << "Adj has been squared" << endl;

    //print results
    print_matrix(Path2, v, v);

    free(Adj);
    free(Path2);
    return 0;
}

