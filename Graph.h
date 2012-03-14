#ifndef GRAPH_H
#define GRAPH_H

#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "SquareMatrix.h"


using namespace std;

class Graph {
public:
   
    // graph with v vertices and no edges
    Graph(int v) : mV(v) {
        mAdj = new SquareMatrix(mV);
        mPath2 = new SquareMatrix(mV);
        this->set_paths_len_2();
    }

    // graph with provided adjacency matrix Adj
    Graph(SquareMatrix* Adj) {
        mV = Adj->size();
        mAdj = Adj->deep_copy();
        mPath2 = new SquareMatrix(mV);
        this->set_paths_len_2();
    }

    // choose a premade example graph
    Graph(const char *example); 

    virtual ~Graph() {
        delete mAdj, mPath2;
    }

    void print();

protected:

    void set_paths_len_2();

    int mV;
    SquareMatrix *mAdj, *mPath2;

};


#endif
