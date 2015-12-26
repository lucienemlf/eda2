/**
Maria Luciene Felix   12/0037742
Paulo Tada            11/0135431
*/
#include <iostream>
#include <stdio.h>
#include <set>
#include <cstring>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <limits.h>

using namespace std;

void dijkstra(vector<list <pair<int, int> > > graph, int start_vertex) {
 
  set<pair<int,int> > distance;
  pair<int,int> start;
  set<pair<int,int> >::iterator it;

  distance.insert(make_pair(0,start_vertex));

  for(int i = 1; i < graph.size(); i++) // Inicializa todas as posições com distancia = infinito e add todos os vertices
    distance.insert(make_pair(INT_MAX, i));

  while(!distance.empty()) {

	   it = distance.begin();
	   start = *it;

	   cout << start.second <<": menor caminho:  " << start.first << endl;
	   distance.erase(it);
	   
	   list<pair<int, int> >::iterator temp = graph[start.second].begin(); // Primeiro valor da lista de adjacencia do start_vertex

	    while(temp != graph[start.second].end()){ 

	      for(it = distance.begin(); it != distance.end(); it++){
	       
					if(it->second == ((*temp).first)  &&  ((*temp).second + start.first) <= it->first) {
						distance.erase(it);
						distance.insert(make_pair(((*temp).second + start.first), (*temp).first));
						break;
					}
	      }
	      temp++;
  		}
  	}
}


void print_graph(vector<list <pair<int, int> > > graph){
  printf("\nThe Adjacency List-\n");
    
	for (int i = 0; i < graph.size(); ++i) {
        printf("%d: ", i);
         
        list< pair<int, int> >::iterator itr = graph[i].begin();
         
        while (itr != graph[i].end()) {
            printf(" -> %d(%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }
}

void menu(){
	cout << "Options: " << endl;
	cout << "1. Insert vertex in the graph." << endl;
	cout << "2. Print the graph." << endl;
	cout << "3. Find the shortest path between two vertex. " << endl;
	cout << "4. Exit." << endl;
}  

int main(){
	int vertex = 0, option;

	cout << "Please insert the numbers of vertex: " << endl;
	cin >> vertex;

	int MAX_EDGES = ((vertex-1)*vertex)/2;	
	vector<list <pair<int, int > > > graph(vertex);
		
	do{
		menu();
		cin >> option;

		switch(option){
			case 1:{
				int count = MAX_EDGES;
				int origin, destiny;
				unsigned int weight;
				char add_edge;
				while(count--){
				  cout << "Please insert the origin, destiny and weight: ";
				  cin >> origin >> destiny >> weight;
				  graph[origin].push_back(make_pair(destiny, weight));
				  graph[destiny].push_back(make_pair(origin, weight));
					cout << "Do you want to insert another vertex S/N? " << endl;
					cin >> add_edge;
					if(add_edge == 'n' || add_edge == 'N' ) break;
				}
				if(!count) cout << "The graph is full" << endl;	
				break;}
			case 2:{
				print_graph(graph);
		   	break;}
			case 3:{
				int start_vertex = 0;
			  cout << "Please insert the start vertex: "<< endl;
				cin >> start_vertex;
				dijkstra(graph, start_vertex);
				break;}
		}

	}while(option != 4);	
	
	return 0;
}
