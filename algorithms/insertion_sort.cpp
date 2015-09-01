/*
Insertion Sort O(n²)
Mais eficiente quando os elementos estao ordenados.
Realiza menos trocas.
*/

#include <iostream>
#include <stdlib.h>
#include "vector_preconfig.h"

using namespace std;

// Insertion sort
void insertion_sort(int vector[], int max_size){
  int aux;
  for(int i = 1 ; i<max_size ; i++){
    for(int j = i ; j >= 1 && vector[j] < vector[j-1] ; j--){
      swap(vector,j,j-1);
    }
  }
}

int main(){

  cout << "Enter the max size of the vector: ";
  int max_size = 0;
  cin >> max_size;

  int vector[max_size];
  cout << "-----------------Not sorted vector-----------------" << endl;
  preconfig(vector, max_size);
  print_vector(vector, max_size);
  cout << "-------------------Sorted vector-------------------" << endl;
  insertion_sort(vector, max_size);
  print_vector(vector, max_size);

  return 0;

}
