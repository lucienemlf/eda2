#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "vector_preconfig.h"
#include "heap.h"

using namespace std;

/* 
   Coloca o maior elemento na ultima posição e 
   realiza um heapify nos elementos restantes
   fazendo com que o maior apareça na primeira 
   posição novamente.
*/

void heap_sort(int array[], int array_size){
  int sort[array_size];
  // Insert random number to the array size: array_size
  for(int i = 1; i<=array_size ; i++){
    insert_heap(array,random_num(),i);
  }

  // Remove from a array to a order array
  for(int i = array_size; i>=0 ; i--){
    extract_max(array,sort,i);
  }
}

int main(){
  int max_size = 10;
  int array[max_size];
  preconfig(array,max_size);
  print_vector(array,max_size);
	heap_sort(array,max_size);	
  print_vector(array,max_size);
	return 0;
}
