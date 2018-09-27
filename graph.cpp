#include <iostream>
#include <fstream>


void makeSat(int* edge_arr, int v, int e, int k){
    ofstream outfile;
    outfile.open ("test.satoutput");
    string one = constraint_one();
    
    outfile << "Writing this to a file.\n";
    outfile.close();

}
