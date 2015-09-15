#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "vector_preconfig.h"

using namespace std;

int extract_max(int array[], int left, int right, int root);
void heapify(int array[], int i, int array_size);
void build_heap(int array[], int array_size);
void heap_sort(int array[], int array_size);
void print_heap(int array[], int array_size);

int main(){
  int max_size = 10;
	int array[max_size];
  preconfig(array,max_size);
	heap_sort(array, max_size);
	
	return 0;
}

/* 
   Coloca o maior elemento na ultima posição e 
   realiza um heapify nos elementos restantes
   fazendo com que o maior apareça na primeira 
   posição novamente.
*/


void remove_heap(int array[],int size){
  array[0] = array[size];
  heapify(array,0,size);
}

void insert_heap(int array[], int element, int position, int size){
  array[position] = element;
  heapify(array,position,size);
}

void heap_sort(int array[], int array_size){

  int new_array[array_size];

  for(int i = 0; i<array_size ; i++){
    insert_heap(new_array,array[i],i,array_size);
  }
  for(int i = 0; i<array_size ; i++){
    array[i] = new_array[0];
    remove_heap(new_array,array_size-i);
  }
  print_vector(new_array, array_size);
  print_vector(array, array_size);
}

void heapify(int array[], int i, int array_size) {
	int left = 2*i;
	int right = 2*i + 1;
	int max_child = 0;

	if(left < array_size && right < array_size){
		
		max_child = extract_max(array, left, right, i);

		if(max_child != i){
			swap(array[i], array[max_child]);
			heapify(array, max_child, array_size);
		}
	}
}

// Retorna o maior filho
int extract_max(int array[], int left, int right, int root){
	int max_child = 0;

	if(array[left] > array[root]){
		max_child = left;
	}else{
		max_child = root;
	}

	if(array[right] > array[max_child]){
		max_child = right;
	}	

	return max_child;
}
