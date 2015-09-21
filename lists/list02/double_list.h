#include<stdio.h>
using namespace std;

typedef struct node Node;
typedef struct list List;

List* init();
void print_list();

struct node{
  int key;
  int data;
  Node* next;
  Node* prev;
};

struct list{
  Node* first;
  Node* last;
  int num_nodes;
};

List* init(){
  List* new_list = (List*) malloc (sizeof(List));
  new_list->first = NULL;
  new_list->last = NULL;
  new_list->num_nodes = 0;
  return new_list;
}

void print_node(Node* node){
  cout << "-----Node-----" << endl;
  if(node){
    cout << "key: " << node->key << endl;
    cout << "data: " << node->data << endl;
    if(node->next){
      cout << "next: " << node->next->key << endl;
      cout << "next->prev:" << node->next->prev->key << endl;
    }else{
      cout << "No NEXT node!" << endl;
    }
    if(node->prev){
      cout << "prev>" << node->prev->key << endl;
      cout << "prev->next:" << node->prev->next->key << endl;
    }else{
      cout << "No PREV node!" << endl;
    }
  }else{
    cout << "NULL Node!" << endl;
  }
  cout << "-----/node-----" << endl;
}

void print_list_reverse(List* list){
  Node* print = list->last;
  while(print != NULL){
    cout << "(" << print->key << ")"<< print->data << " ";
    print = print->prev;
  }
}

void print_list(List* list){
  Node* print = list->first;
  while(print != NULL){
    cout << "(" << print->key << ")"<< print->data << " ";
    print = print->next;
  }
}

void insert(List* list, int element){
  Node* new_node = (Node*) malloc (sizeof(Node));
  new_node->data = element;
  new_node->next = NULL;

  if(list->num_nodes == 0){
    new_node->prev = NULL;
    new_node->key = 0;
    list->first = new_node;
    list->last = new_node;
  }else{
    new_node->prev = list->last;
    new_node->key = new_node->prev->key + 1;
    list->last->next = new_node;
    list->last = new_node;
  }
  list->num_nodes++;
}

Node* search(List* list, int key){
  Node* result = NULL;
  Node* search = list->first;
  while(search != NULL){
    if(search->key == key){
      result = search;
      break;
    }
    search = search->next;
  }
  return result;
}
