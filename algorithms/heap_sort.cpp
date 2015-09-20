/* Arvore binária
  - inserção nlog(n)
  - remoção nlog(n)

  Implementação em vetor
  - PARENT (i) = floor(i/2)
  - LEFT (i) = 2*i
  - RIGHT (i) = 2*i + 1
*/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "vector_preconfig.h"

int parent(int position);
int left_child(int position);
int right_child(int position);

void build_heap();
void heapfy(int vector[], int size, int position);
void build_heap(int vector[]);
void extract_max(int vector[]);
void heap_sort(int vector[]);

int main(){
}

void heapify(int vector[], int dad){
  int larger = get_max(vector,dad);

  if(larger != dad){
    swap(vector[dad], vector[larger]);
    heapify(vector,larger);
  }
}

int get_max(int vector[], int dad){
  int left = left_child(dad);
  int right = right_child(dad);
  int larger = 0;
  
  if(left <= sizeof(vector) && vector[left] > vector[dad]){
    larger = left;
  }else{
    larger = dad;
  }

  if(right <= sizeof(vector) && vector[right] > vector[dad]){
    larger = right;
  }

  return larger;
}

void build_heap(int vector[]){
  int size = sizeof(vector)/4;
  for(int i = floor(size/2); i>=0 ; i--){
    heapify(vector, i);
}

void extract_max(int vector[]){
  int size = sizeof(vector);

  swap(vector[0], vector[size-1]);
}

void insert(int vector[], int element){
  int size = sizeof(vector)/4;
  vector[size] = element;
  
  int position = (sizeof(vector)/4) - 1;
  int dad = parent(position);
  while(position>1 && vector[dad]<vector[position]){
    swap(vector[dad],vector[dad]);
  }
}

void heap_sort(int vector[]){
  
}

int parent(int position){
  int parent = floor(position/2);
  return parent;
}

int left_child(int position){
  int left_child = position*2;
  return left_child;
}

int right_child(int position){
  int right_child = position*2 + 1;
  return right_child;
}
