#include "graph.h"
#include <iostream>
#include <fstream>
using namespace std;

void Graph::print_nk(int n, int k){
    ofstream outfile;
    outfile.open ("file_nk");
    outfile <<n<<endl<<k<<endl;
    outfile.close();
}

Graph::Graph(string inFile){
    ifstream infile(inFile);
    int v,e,k;
    infile >> v >> e >> k;
    // cout<<v<<" "<<e<<" "<<k<<endl;
    num_vertices = v;
    num_edges = e;
    k_agencies = k;
    z_count = v*k;
    num_clauses=0;
    num_literals=0;

    print_nk(v,k);

    // edge_array = new int*(num_vertices);
    edge_array = (int**)malloc(sizeof(int*)*num_vertices);
    // cerr<<"check\n";
    
    for(int i=0;i<num_vertices;i++){
    	// edge_array[i] = new int(num_vertices);
        // cerr << "check i: "<< i<< endl;
        edge_array[i] = (int*)malloc(sizeof(int)*num_vertices);
    }
    // cout << "Random" << endl;
    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<num_vertices;j++){
            // cerr << "i :" << i << " j: " << j << endl;
            // cerr << edge_array[i][j]<<endl;
            edge_array[i][j]=(i==j?1:0);
        }
    }
    // cout << "Random" << endl;

    for (int i =0; i< e; i++){
        int v1,v2;
        infile >> v1>> v2 ;
        v1--;
        v2--;
        edge_array[v1][v2] = 1;
        edge_array[v2][v1] = 1;
    }
    // cout << "Check2" << endl;
    
}

void Graph::makeSat(){
    ofstream outfile;
    outfile.open ("test.satinput");
    
    string constraints = "";
    // constraints+=constraint_one();
    constraints+=constraint_four();
    cout<<num_clauses<<endl;
    // constraints+=constraint_three();
    constraints+=constraint_two();
    cout<<num_clauses<<endl;
    cout<<"ratio c/v = "<<num_clauses/(float)z_count<<endl;
    cout<<"avg clause length = "<<num_literals/(double)num_clauses<<endl;
    // outfile << "Writing this to a file.\n";
    outfile << "p cnf "<<z_count<<" "<<num_clauses<<endl;
    outfile << constraints;
    outfile.close();

}



bool Graph::check_edge(int u, int v){
	if (edge_array[u][v] == 1){
		return true;
	}
	return false;
}

string Graph::literal(int i,int j){
	// string str="";
	int n = i*(this->k_agencies) + j + 1;
	return to_string(n);
}

string Graph::constraint_one(){
	string str="";

	for(int i=0;i<num_vertices;i++){
		for(int j=0;j<k_agencies;j++){
			str+=literal(i,j)+" ";
		}
		str+="0\n";
        num_clauses++;
	}

	return str;
}

string Graph::constraint_two(){
    string mySol = "";
    for (int i = 0; i< num_vertices; i++){
        for (int t= i+1 ; t< num_vertices; t++){
            //Case 1: Edge Not Present
            if (edge_array[i][t] == 0){
                for (int j=0; j<k_agencies ; j++){
                    string node1 = literal(i,j);
                    string node2 = literal(t,j);
                    mySol += "-" + node1 + " " + "-"+ node2 + " 0\n";
                    num_clauses++;
                    num_literals+=2;
                }
            }
            //Case 2: Edge Present
            else{
                for (int j=0; j<k_agencies; j++){
                    string node = to_string(z_count + j + 1);
                    mySol += node + " ";
                }
                num_literals+=k_agencies;
                mySol += "0\n";
                num_clauses++;
                for (int j=0; j<k_agencies; j++){
                    string node_z = to_string(z_count + j + 1);
                    string node1 = literal(i,j);
                    string node2 = literal(t,j);
                    mySol += "-" + node_z + " " + node1 + " 0\n" + "-" + node_z + " " + node2 + " 0\n";
                    num_clauses+=2;
                    num_literals+=4;
                }
                z_count += k_agencies;
            } 
        }
    }

    return mySol;
}


string Graph::constraint_three(){
	string str="";
    string temp;
    /*
    // Case 3a:
	temp="";
    for(int i=0;i<num_vertices;i++){
		for(int j=0;j<k_agencies;j++){
            for(int t=0;t<num_vertices;t++){
                
                //Case 1: Edge Present - 3a satisfied always

                //Case 2: Edge not present
                if(!check_edge(i,t)){
                    temp+="-"+literal(i,j)+" -"+literal(t,j)+" 0\n";
                    num_clauses++;
                }
            }
		}
	}
    str+=temp;
    // cerr<<"check in \n";
    */    
    //Case 3b:
    temp="";
    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<k_agencies;j++){
            for(int t=0;t<num_vertices;t++){
                if(check_edge(i,t)){
                    // Case 1: Edge present
                } else{
                    // Case 2: Edge not present
                    temp+=literal(t,j)+" ";
                }
            }
            temp+=literal(i,j)+" 0\n";
            num_clauses++;
        }
    }
    str+=temp;

    return str;
}


string Graph::constraint_four(){
    string mySol = "";
    for (int p = 0; p<k_agencies; p++){
        for (int q=0; q< k_agencies; q++){
            if(p==q)
                continue;
            for (int i=0; i< num_vertices; i++){
                string node = to_string(z_count + i + 1);
                mySol += node + " ";
            }
            num_literals+=num_vertices;
            mySol += "0\n";
            num_clauses++;
            for (int i=0; i< num_vertices; i++){
                string node_z = to_string(z_count + i + 1);
                string node1 = literal(i,p);
                string node2 = literal(i,q);
                mySol += "-" + node_z + " " + node1 + " 0\n" + "-" + node_z + " -" + node2 + " 0\n";
                num_clauses+=2;
                num_literals+=4;
            }
            z_count += num_vertices;
        }
    } 

    return mySol;
}