#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

using namespace std;

int extract_max(int array[], int left, int right, int root);
void heapify(int array[], int i, int array_size);
void build_heap(int array[], int array_size);
void heap_sort(int size);
void print_heap(int array[], int array_size);

int main(){

	
	clock_t begin_time,end_time;
  	float diff = 0;
  	float seconds = 0;

    begin_time= clock();
	heap_sort(SIZE);
    end_time=clock();

    diff =  ((float)end_time-(float)begin_time);
    seconds = diff / CLOCKS_PER_SEC;

    cout <<"  Tempo de de execução(s): " << seconds << endl;	

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

/* 
   Coloca o maior elemento na ultima posição e 
   realiza um heapify nos elementos restantes
   fazendo com que o maior apareça na primeira 
   posição novamente.
*/


void heap_sort(int size) {
  cout << "   Vetor com " << size << " elementos: " << endl;
  int array[size];

  // Popula array com numeros aleatórios
  for (int i = 0; i < size; ++i)
  {
  	array[i] = rand() % size;
  }

  build_heap(array, size);

  for (int i = size-1; i > 1; i--)
  {
    swap(array[0], array[i]);
    heapify(array, 0, i-1);
  }
  
  print_heap(array, size);
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