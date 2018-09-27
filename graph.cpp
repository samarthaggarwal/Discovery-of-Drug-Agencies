#include <iostream>
#include <fstream>


Graph::Graph(string inFile){
	std::ifstream infile(inFile);
    int v,e,k;
    infile >> v >> e >> k;
    num_vertices = v;
    num_edges = e;
    k_agencies = k;

    edge_array = new int*(num_vertices);
    for(int i=0;i<v;i++){
    	edge_array[i] = new int(num_vertices);
    }
    for (int i =0; i< e; i++){
        int v1,v2;
        infile >> v1>> v2 ;
        edge_array[v1][v2] = 1;
        edge_array[v2][v1] = 1;
    }

}

void Graph::makeSat(int* edge_arr, int v, int e, int k){
    ofstream outfile;
    outfile.open ("test.satoutput");
    string one = constraint_one();
    
    outfile << "Writing this to a file.\n";
    outfile.close();

}
