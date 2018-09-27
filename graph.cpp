#include <iostream>
#include <fstream>


void makeSat(int* edge_arr, int v, int e, int k){
    ofstream outfile;
    outfile.open ("test.satoutput");
    string one = constraint_one();
    
    outfile << "Writing this to a file.\n";
    outfile.close();

}

string constraint_one(){

}


bool check_edge(int u, int v){
	if (edge_array[u][v] == 1){
		return true;
	}
	return false;
}