#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char** argv){
    ifstream infile(argv[1]);
    string str;
    infile>>str;
    // cout<<str<<endl;
    if(str=="UNSAT"){
        cout<<"0\n";
    } else {
        ifstream graph("test.graph");
        int n,m,k;
        graph >> n >> m >> k;
        
    }

    return 0;
}