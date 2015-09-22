#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "heap.h"

using namespace std;

int get_max(int array[], int left, int right, int root);
int extract_max(int array[], int size);
void build_heap(int array[], int array_size);
void print_heap(int array[], int array_size);
void insert_heap(int array[], int element, int size);
void heapify_up(int array[], int size);
void heapify(int array[], int i, int array_size);
void heap_sort(int array[], int numbers[], int array_size);

int main(){
	int array_size = 8;
	int array[array_size];
    int numbers[] = {10, 35, 6, 8, 3, 90, 1, 78};
  	
  	print_heap(numbers, array_size);

  	// Inicializa vetor com zeros
	memset(array, 0, sizeof(array));

	heap_sort(array, numbers, array_size);
	
	return 0;
}

void heap_sort(int array[], int numbers[], int array_size){
  int sort[array_size];
  memset(sort, 0, sizeof(sort));

  for(int i = 0; i < array_size ; i++){
    insert_heap(array,numbers[i],i);
  }
  
  for(int i = array_size-1; i >= 0 ; i--){
    sort[i] = extract_max(array, i);
  }

  print_heap(sort, array_size);

}

int extract_max(int array[], int size){
   int maximo;
   if(size > 1){
      maximo = array[1];
      array[1] = array[size+1];
      heapify(array, 1, size+1);
   } else if(size == 1){
      maximo = array[1];
      size = 0;
   } else {
      maximo = -1;
   }
   return maximo;
}


// Coloar todos os filhos maiores na raiz
void heapify(int array[], int i, int array_size) {
	int left = 2*i;
	int right = 2*i + 1;
	int max_child = 0;

	if(left < array_size && right < array_size){
		
		max_child = get_max(array, left, right, i);

		if(max_child != i){
			swap(array[i], array[max_child]);
			heapify(array, max_child, array_size);
		}
	}
}

void insert_heap(int array[], int element, int size){
	size++;   // Primeiro elemento começa na posição 1
	array[size] = element;
	heapify_up(array, size);
}
void heapify_up(int array[], int index) {
	while(index>1){
		if(array[index]>array[index/2]){
			swap(array[index],array[index/2]);
		}
		index/=2;
	}
}




void print_heap(int array[], int array_size) {
	for (int i = 1; i < array_size; ++i)
	{
		printf("%d ", array[i]);
		if (array[i] != array[array_size-1])
			cout << ",";
	}
	cout << endl;
}


// Retorna o maior filho
int get_max(int array[], int left, int right, int root){
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
