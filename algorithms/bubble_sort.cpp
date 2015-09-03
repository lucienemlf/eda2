#include<iostream>
#include<stdlib.h>
#include "vector_preconfig.h"

using namespace std;

void bubble_sort(int vector[], int max_size){
  for(int i=0 ; i<max_size ; i++){
    bool swapped = false;
    for(int j=max_size ; j>i ; j--){
      if(vector[j] < vector[j-1]){
        swap(vector,j,j-1);
        swapped = true;
      }
    }
    if(swapped==false){break;}
  }
}

int main(){
  cout << "Enter the max size of the vector: ";
  int max_size = 0;
  cin >> max_size;
  
  int vector[max_size];
  cout << "-------- Not sorted ---------" << endl;
  preconfig(vector, max_size);
  print_vector(vector, max_size);
  cout << "---------- Sorted -----------" << endl;
  bubble_sort(vector, max_size);
  print_vector(vector, max_size);
  return 0;
}
