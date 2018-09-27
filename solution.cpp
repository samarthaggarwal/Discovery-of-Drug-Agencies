#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char** argv){
    ifstream infile(argv[1]);
    string str;
    infile>>str;
    // cout<<str<<endl;
    if(str=="UNSAT"){

    } else {
        
    }

    return 0;
}