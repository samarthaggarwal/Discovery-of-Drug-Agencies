#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main(int argc, char** argv) {
    Graph satSolver(argv[1]);

    satSolver.makeSat();

    return 0;
}
