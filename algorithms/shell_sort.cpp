/*
Shell Sort O(n²)
Mais eficiente dos algoritmos de complexidade quadraticas.
*/
#include <iostream>
#include <stdlib.h>
#include "vector_preconfig.h"

void shell_sort(int vector[], int max_size){
  int gap = max_size/2;
  int number, j;
  while(gap>0){
    for(int i=gap; i<max_size ; i++){
      number = vector[i];
      j = i;
      while(j>=gap && vector[j-gap] > number){
        vector[j] = vector[j-gap];
        j -= gap;
      }
      vector[j] = number;
    }
    gap /= 2;
  }
}

int main(){ 
  int max_size = 0;
  cout << "Enter the max size of the vector: ";
  cin >> max_size;

  int vector[max_size];
  preconfig(vector,max_size);
  cout << "=== Random Vector ===" << endl;
  print_vector(vector,max_size);

  cout << "=== Sort Vector ===" << endl;
  shell_sort(vector,max_size);
  print_vector(vector,max_size);
  return 0;
}
