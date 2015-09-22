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
void heap_sort(int vector[]);
void insert(int vector[], int element, int size);
int extract_max(int vector[]);
int get_max(int vector[], int dad);

int main(){
  int vector[10];
  for(int i=0; i<10 ; i++)
    insert(vector,i*3,10);

  print_vector(vector,10);
  return 0;
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

int extract_max(int vector[]){
  int size = sizeof(vector);
  int max_int = vector[0];

  swap(vector[0], vector[size-1]);
  vector = (int*)realloc(vector,sizeof(vector)-4);
  return max_int;
}

void insert(int vector[], int element, int size){
  vector[size] = element;
  
  int position = (sizeof(vector)/4) - 1;
  vector = (int*)realloc(vector,sizeof(vector)+4);

  int dad = parent(position);
  while(position>1 && vector[dad]<vector[position]){
    swap(vector[dad],vector[position]);
  }
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
