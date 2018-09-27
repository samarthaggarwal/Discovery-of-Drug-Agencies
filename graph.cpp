#include "graph.h"

Graph::Graph(string inFile){
    ifstream infile(inFile);
    int v,e,k;
    infile >> v >> e >> k;
    // cout<<v<<" "<<e<<" "<<k<<endl;
    num_vertices = v;
    num_edges = e;
    k_agencies = k;
    z_count = v*k;

    // cerr<<"check\n";
    // edge_array = new int*(num_vertices);
    edge_array = (int**)malloc(sizeof(int)*num_vertices);
    // cerr<<"check\n";
    
    for(int i=0;i<v;i++){
    	// edge_array[i] = new int(num_vertices);
        edge_array[i] = (int*)malloc(sizeof(int)*num_vertices);
    }
    // cerr<<"check\n";
    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<num_vertices;j++){
            edge_array[i][j]=0;
        }
    }
    // cerr<<"check\n";
    for (int i =0; i< e; i++){
        int v1,v2;
        infile >> v1>> v2 ;
        v1--;
        v2--;
        edge_array[v1][v2] = 1;
        edge_array[v2][v1] = 1;
    }
    // cerr<<"check\n";
    
}

void Graph::makeSat(){
    ofstream outfile;
    // cerr<<"check\n";
    outfile.open ("test.satoutput");
// cerr<<"check\n";
    
    string constraints = "";
    // cerr<<"check1\n";
    constraints+=constraint_one();
    // cerr<<"check2\n";
    constraints+=constraint_two();
    // cerr<<"check3\n";
    constraints+=constraint_three();
    // cerr<<"check4\n";
    constraints+=constraint_four();
    // cerr<<"check5\n";
    
    outfile << "Writing this to a file.\n";
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
	int n = i*(this->num_vertices) + j;
	return to_string(n);
}

string Graph::constraint_one(){
	string str="";

	for(int i=0;i<num_vertices;i++){
		for(int j=0;j<num_vertices;j++){
			str+=literal(i,j)+" ";
		}
		str+="0\n";
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
                }
            }
            //Case 2: Edge Present
            else{
                for (int j=0; j<k_agencies; j++){
                    string node = to_string(z_count + j);
                    mySol += node + " ";
                }
                mySol += "0\n";
                for (int j=0; j<k_agencies; j++){
                    string node_z = to_string(z_count + j);
                    string node1 = literal(i,j);
                    string node2 = literal(t,j);
                    mySol += "-" + node_z + " " + node1 + " 0\n" + "-" + node_z + " " + node2 + " 0\n";
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

    // Case 3a:
	temp="";
    for(int i=0;i<num_vertices;i++){
		for(int j=0;j<k_agencies;j++){
            for(int t=0;t<num_vertices;t++){
                if(i==t)
                    continue;
                
                //Case 1: Edge Present - 3a satisfied always

                //Case 2: Edge not present
                if(!check_edge(i,t)){
                    temp+="-"+literal(i,j)+" -"+literal(t,j)+" 0\n";
                }
            }
		}
	}
    str+=temp;
    // cerr<<"check in \n";
    
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
        }
    }
    str+=temp;

    return str;
}


string Graph::constraint_four(){
    string mySol = "";
    for (int p = 0; p<k_agencies; p++){
        for (int q=p+1; q< k_agencies; q++){
            for (int i=0; i< num_vertices; i++){
                string node = to_string(z_count + i);
                mySol += node + " ";
            }
            mySol += "0\n";
            for (int i=0; i< num_vertices; i++){
                string node_z = to_string(z_count + i);
                string node1 = literal(i,p);
                string node2 = literal(i,q);
                mySol += "-" + node_z + " " + node1 + " 0\n" + "-" + node_z + " -" + node2 + " 0\n";
            }
            z_count += num_vertices;
        }
    } 

    return mySol;
}