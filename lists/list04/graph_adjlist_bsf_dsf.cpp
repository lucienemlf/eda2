#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <vector>
#include <list>
#define VERTICES 10

using namespace std;

void depth_first_search_explore(vector <list<int> > graph, int parent[],int vertex, int status[]){
	if(parent[vertex] != -1){
	  list<int>:: iterator itr = graph[vertex].begin();
		status[vertex] = 1;

		// Visit all vertices accessible 
		while(itr != graph[vertex].end()){
			if(parent[*itr] == -1){
				parent[*itr] = vertex;
				depth_first_search_explore(graph, parent, *itr, status);
			}else{
				if(status[*itr] == 1)
					cout << vertex << "--->" << *itr << " is a Backward Edge" << endl; 
			}
			itr++;
		}
		status[vertex] = 0;
	}
}

void depth_first_search(vector <list<int> > graph, int start_vertex, int max_edges){
		int parent[max_edges], status[max_edges];
		memset(parent, -1, sizeof(parent));
		memset(status, 0, sizeof(status));
	
		if(parent[start_vertex] == -1){
			parent[start_vertex] = 0;
			depth_first_search_explore(graph, parent, start_vertex, status);
		}
	
	for(int i = 0; i < graph.size(); i++) {
		printf("Parent of vertex %d:  %d\n", i, parent[i]);
	}
}

void bsf(vector <list<int> > graph, int start_vertex, int max_edges){
	list<int>::iterator itr;
	int parent, level = 0;
	int leveis[max_edges], parents[max_edges]; 
	bool flag = true;
	
	memset(parents, 0, sizeof(parents));
	memset(leveis, -1, sizeof(leveis));

  // 1. Mark the first node as level 0				
	leveis[start_vertex] = level;

	while(flag) {
		flag = false;
		for(int i = start_vertex; i < graph.size(); i++) {
			if(leveis[i] == level){
				flag = true;
				itr = graph[i].begin();
				parent = i;
	
				// Mark all the neibohods as leve 1				
				while(itr != graph[i].end()){
					if(leveis[*itr] != -1){
						++itr;
						continue;
					}else{
					  leveis[*itr] = level + 1;
					  parents[*itr] = parent;
					  itr++;
					}
				}
			}
		}
		++level;
		start_vertex = 0;
	}
	
	// Printing the leveis
	for(int i  = 0; i < graph.size(); i++){
		printf("%d: level: %d parent: %d\n", i, leveis[i], parents[i]);
	}
	
}

void print_graph(vector <list<int> > graph){
	cout << "Lista de adjacencias: " << endl;
	for(int i = 0; i < graph.size();  i++){
			list<int>::iterator itr = graph[i].begin();
			cout << i << ": ";	
			while(itr != graph[i].end()){
					cout << " -> " << (*itr);
					itr++;
			} 
		cout << "\n" << endl;
	}
}
void menu(){
	cout << "Menu de opções" << endl;
	cout << "1. Inserir nós no gráfico." << endl;
	cout << "2. Imprimir gráfico." << endl;
	cout << "3. Busca em largura. " << endl;
	cout << "4. Busca em profundidade." << endl;
	cout << "5. Sair" << endl;
}

int main(){
	int option = 0;
  int vertex = 0;

	cout << "Please insert the numbers of vertex: " << endl;
	cin >> vertex;

	int MAX_EDGES = ((vertex-1)*vertex)/2;	
	int count  = MAX_EDGES;
	vector<list<int> > graph(vertex);
		
	do{
		menu();
		cin >> option;

		switch(option){
			case 1:{
				int origin, destiny;
				char add_edge;
				while(count--){
				  cout << "Please insert the origin and destiny: ";
				  cin >> origin >> destiny;
				  graph[origin].push_back(destiny);
				  graph[destiny].push_back(origin);
					cout << "Do you want to insert another node S/N? " << endl;
					cin >> add_edge;
					if(add_edge == 'n' || add_edge == 'S' ) break;
				}
				if(!count) cout << "The graph is full" << endl;	
				break;}
			case 2:{
				print_graph(graph);
		   	break;}
			case 3:{
				int start_vertex;
			  cout << "Please insert the start_vertex: "<< endl;
				cin >> start_vertex;
				bsf(graph, start_vertex, MAX_EDGES);
				break;}
			case 4:{
  			int start_vertex;
    	  cout << "Please insert the start_vertex: "<< endl;
				cin >> start_vertex;
	 			depth_first_search(graph,start_vertex, MAX_EDGES);
			break;}
		}

	}while(option != 5);	
	
	return 0;
}
