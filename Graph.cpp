#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Graph.h"

using namespace std;

class Graph;

void Graph::set_paths_len_2() {
    mPath2 = mAdj->squared();
}

Graph::Graph(const char *example) {
    const char *3arm222star = "3arm222star";
    int edge_index = 0;
    if ( strcmp(example, 3arm222star) == 0 ) {
        mV = 7;
        mAdj = new SquareMatrix(mV);
        int edges[] = {0,1,0,1,0,1,0,
                       1,0,1,0,0,0,0,
                       0,1,0,0,0,0,0,
                       1,0,0,0,1,0,0,
                       0,0,0,1,0,0,0,
                       1,0,0,0,0,0,1,
                       0,0,0,0,0,1,0 };
        for (int i = 0; i < mV; i++) {
            for (int j = 0; j < mV; j++) {
                mAdj->write( i, j, edges[edge_index] );
                edge_index++;
            }
         }
         mPath2 = new SquareMatrix(mV);
         this->set_paths_len_2();
    }

    else {
        cout << "requested graph example not recognized; creating default" << endl;
        mAdj = new SquareMatrix(5);
        mPath2 = new SquareMatrix(5);
        this->set_paths_len_2();
    }
}

void Graph::print() {
    cout << "graph with adjacency matrix" << endl;
    mAdj->print();
    cout << "and paths of length 2" << endl;
    mPath2->print();
    cout << "end of graph printing" << endl;
}
