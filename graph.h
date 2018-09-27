#include <iostream>
#include <fstream>


using namespace std;

class Graph{

public:
    int** edge_array;             // array of paper
    int num_vertices;    			// number of nodes
    int num_edges;
    int k_agencies;

    Graph(string inFile){
    	std::ifstream infile(argv[1]);
	    int v,e,k;
	    infile >> v >> e >> k;
	    num_vertices = v;
	    num_edges = e;
	    k_agencies = k;

	    int edge_array[v][v] = {};
	    for (int i =0; i< e; i++){
	        int v1,v2;
	        infile >> v1>> v2 ;
	        edge_array[v1][v2] = 1;
	        edge_array[v2][v1] = 1;
	    }

    }

    void makeSat();
    string constraint_one();
    bool check_edge(int u, int v);


}