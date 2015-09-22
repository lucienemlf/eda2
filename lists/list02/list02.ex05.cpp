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
  Node* first = search(list,fk);
  Node* second = search(list,sk);

  int key = first->key;
  int data = first->data;
  Node* prev = first->prev;
  Node* next = first->next;

  first->key = second->key;
  first->data = second->data;
  first->prev = second->prev;
  first->next = second->next;

  second->key = key;
  second->data = data;
  second->prev = prev;
  second->next = next;

  // Exchange
  second->key = first->key;
  first->key = key;
  second->prev = first->prev;
  second->next = first->next;
  first->prev = prev;
  first->next = next;
}

void quick_sort(List* list, int left, int right){
  Node* pivo_node = search(list, left);
  int i = left;
  int j = right;

  int pivo = pivo_node->data;

  while(i<=j){
    while(search(list,i)->data < pivo && i < right){
      i++;
    }
    while(search(list,j)->data > pivo && j > left){
      j--;
    }
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
