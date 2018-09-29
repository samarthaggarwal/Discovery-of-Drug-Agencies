#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main(int argc, char** argv) {
	// cout << "check\n";
    Graph satSolver(argv[1]);
    // cout << "Sat satSolver Init\n";
    satSolver.makeSat(argv[1]);

    return 0;
}
