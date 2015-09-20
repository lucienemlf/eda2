#include<iostream>
#include<stdlib.h>
#include "vector_preconfig.h"

void selection_sort(int vector[], int max_size){
  for(int i=0 ; i<max_size ; i++){
    int k = i;
    for(int j=i+1 ; j<max_size ; j++){
      if(vector[j] < vector[k]){
        k = j;
      }
    }
    swap(vector[i],vector[k]);
  }
}

int main(){
  int max_size = 0;
  cout << "Enter the max size of the vecotr: ";
  cin >> max_size;

  int vector[max_size];
  preconfig(vector,max_size);
  cout << "=== Random Vector ===" << endl;
  print_vector(vector,max_size);

  cout << "=== Sort Vector ===" << endl;
  selection_sort(vector,max_size);
  print_vector(vector,max_size);
  
  return 0;
}
