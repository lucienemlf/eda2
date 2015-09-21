#include <iostream>
#include <vector>
#include <stdlib.h>
#include "double_list.h"
#include "vector_preconfig.h"

void radomlist(List* list){
  insert(list,4);
  insert(list,6);
  insert(list,1);
  insert(list,8);
  insert(list,4);
  insert(list,2);
  insert(list,3);
}

void swap(List* list, int fk, int sk){
  Node* tmp = (Node*) malloc(sizeof(Node));
  Node* first = search(list,fk);
  Node* second = search(list,sk);

  cout<< "=======================" << endl;
  print_node(list->first);
  print_node(list->last);
  cout<< "=======================" << endl;

  int key = second->key;
  int data = second->data;
  Node* prev = second->prev;
  Node* next = second->next;

  //if(second->next) second->next->prev = first;
  //if(second->prev) second->prev->next = first;

  //second->key = first->key;
  second->data = first->data;
  second->prev = first->prev;
  second->next = first->next;

  //first->key = key;
  first->data = data;
  first->next = second->next;
  first->prev = second->prev;

  //if(first->next) first->next->prev = second;
  //if(first->prev) first->prev->next = second;

  cout<< "=======================" << endl;
  print_node(list->first);
  print_node(list->last);
  cout<< "=======================" << endl;
}

void quick_sort(List* list, int left, int right){
  Node* pivo_node = search(list, left);
  int i = left;
  int j = right;

  int pivo = pivo_node->data;

  cout << "while 1" << endl;
  while(i<=j){
    cout << "while 2" << endl;
    while(search(list,i)->data < pivo && i < right){
      i++;
    }
    cout << "while 3" << endl;
    while(search(list,j)->data > pivo && j < right){
      j--;
    }
    cout << "swp" << endl;
    if(i<=j){
      swap(list, i, j);
      i++;
      j--;
    }
  }
  if(j > left) quick_sort(list, left, j);
  if(i < right) quick_sort(list, i, right);
}

int main(){
  List* list = NULL;
  list = init();
  radomlist(list);

  print_list(list);
  cout << endl;
  quick_sort(list,0,(list->num_nodes)-1);
  print_list(list);
  cout << endl;
  return 0;

}
