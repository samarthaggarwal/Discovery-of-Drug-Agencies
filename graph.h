#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Graph{

public:
    int** edge_array;             // array of paper
    int num_vertices;    			// number of nodes
    int num_edges;
    int k_agencies;

	Graph();    
    void makeSat();
    string constraint_one();
    string constraint_two();
    string constraint_three();
    string constraint_four();
    string constraint_five();
    bool check_edge(int u, int v);

    string literal(int i,int j);
}