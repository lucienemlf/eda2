// Com base no codigo da busca sequencial, evolua o
// código para uma busca sequencial com índice primário.

#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

typedef struct node{
  int id;
  int value;
}Node;

void preconfig(list<Node>* elements){
  int tests = 0;
  cin >> tests;
  for(int i=0; i<tests ; i++){
    Node new_node;
    cin >> new_node.id;
    cin >> new_node.value;
    elements->push_back(new_node);
  }
}

void print_list(list<Node> elements){
  for(list<Node>::iterator node = elements.begin();node != elements.end(); node++){
		cout << node->value << endl;
	}
}

Node search_node(list<Node> elements, int value){
  Node result;
  for(list<Node>::iterator node = elements.begin();node != elements.end(); node++){
		if(node->value == value){
			result = *node;
			break;
		}
	}
  return result;
}

int main(){
  list<Node> test_list;
  preconfig(&test_list);
	cout << "Searching for 90..." << endl;
	int value = 0;
	cin >> value;
	Node found = search_node(test_list);
  return 0;
}
