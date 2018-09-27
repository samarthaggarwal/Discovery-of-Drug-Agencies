#include <iostream>
#include <fstream>


using namespace std;

void makeSat(int* edge_arr, int v, int e, int k){
    ofstream outfile;
    outfile.open ("test.satoutput");
    outfile << "Writing this to a file.\n";
    outfile.close();

}

int main(int argc, char** argv) {

    Graph satSolver(argv[1])
    satSolver.makeSat();


    return 0;
}
