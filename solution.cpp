#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(int argc, char** argv){
    ifstream infile(argv[1]);
    string str;
    infile>>str;
    // cout<<str<<endl;
    if(str=="UNSAT"){
        cout<<"0\n";
    } else {
        ifstream graph("file_nk");
        int n,k,temp;
        graph >> n >> k;
        vector< vector<int> > member(k);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                infile>>temp;
                // cout<<temp<<endl;
                if(temp>0)
                    member.at(j).push_back(i);
            }
        }

        for(int j=0;j<k;j++){
            cout<<"#"<<j+1<<" "<<member.at(j).size()<<endl;
            for(int i=0;i<member.at(j).size();i++){
                cout<<member.at(j).at(i) + 1<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}