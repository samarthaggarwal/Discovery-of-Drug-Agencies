#include <graph.h>

Graph::Graph(string inFile){
	std::ifstream infile(inFile);
    int v,e,k;
    infile >> v >> e >> k;
    num_vertices = v;
    num_edges = e;
    k_agencies = k;
    z_count = v*k;

    edge_array = new int*(num_vertices);
    for(int i=0;i<v;i++){
    	edge_array[i] = new int(num_vertices);
    }
    for (int i =0; i< e; i++){
        int v1,v2;
        infile >> v1>> v2 ;
        edge_array[v1][v2] = 1;
        edge_array[v2][v1] = 1;
    }

}

void Graph::makeSat(int* edge_arr, int v, int e, int k){
    ofstream outfile;
    outfile.open ("test.satoutput");

    string constraints = "";
    constraints+=constraint_one();
    constraints+=constraint_two();
    constraints+=constraint_three();
    
    outfile << "Writing this to a file.\n";
    outfile.close();

}



bool Graph::check_edge(int u, int v){
	if (edge_array[u][v] == 1){
		return true;
	}
	return false;
}

string Graph::literal(int i,int j, bool value){
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
                string[num_vertices] sum_arr;
                for (int l=0; l<num_vertices; l++){
                    sum_arr[l] = literal(i,l);
                }
                all_all(i,t,0,k)
            } 
        }
    }

}

string Graph::constraint_three(){
	string str="";

	for(int i=0;i<num_vertices;i++){
		for(int j=0;j<k_agencies;j++){

		}
	}
}


