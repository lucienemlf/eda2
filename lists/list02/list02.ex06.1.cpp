#include <iostream>
#include <stdio.h>

using namespace std;

int extract_max(int array[], int left, int right, int root);
void heapify(int array[], int i, int array_size);
void build_heap(int array[], int array_size);
void heap_sort(int array[], int array_size);
void print_heap(int array[], int array_size);

int main(){
	int array[] = {2,7,26,25,19,17,1,90,3,36};

	print_heap(array, 10);
	heap_sort(array, 10);
	print_heap(array, 10);
	
	return 0;
}

void print_heap(int array[], int array_size) {
	for (int i = 0; i < array_size; ++i)
	{
		printf("%d ", array[i]);
		if (array[i] != array[array_size-1])
		{
			cout << ",";
		}
	}
	cout << endl;
}

void heap_sort(int array[], int array_size)
{

  build_heap(array, array_size);

  for (int i = array_size-1; i > 1; i--)
  {
    swap(array[0], array[i]);
    heapify(array, 0, i-1);
  }
}

// Garante que cada sub-arvore seja um heap;
void build_heap(int array[], int array_size) {
	for (int i = (array_size/2)-1; i >= 0; --i)
		heapify(array, i, array_size);
}

// Coloar todos os filhos maiores na raiz
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
