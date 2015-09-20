#include<stdio.h>
using namespace std;

typedef struct node Node;
typedef struct list List;

List* init();
void print_list();

struct node{
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

void print_list_reverse(List* list){
  Node* print = list->last;
  for(int i=0 ; i<list->num_nodes ; i++){
    cout << print->data << " ";
    print = print->prev;
  }
}

void print_list(List* list){
  Node* print = list->first;
  for(int i=0 ; i<list->num_nodes ; i++){
    cout << print->data << " ";
    print = print->next;
  }
}

void insert(List* list, int element){
  Node* new_node = (Node*) malloc (sizeof(Node));
  new_node->data = element;
  new_node->next = NULL;

  if(list->num_nodes == 0){
    new_node->prev = NULL;
    list->first = new_node;
    list->last = new_node;
  }else{
    new_node->prev = list->last;
    list->last->next = new_node;
    list->last = new_node;
  }
  list->num_nodes++;
}
