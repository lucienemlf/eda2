/* Complexidade O(n+m) */
#include<iostream>
#include<stdlib.h>
#include"vector_preconfig.h"

using namespace std;

int merge(int vector[], int max_size){
  int mid;
  int* tmp;
  int top, bot;

  tmp = (int*)malloc(max_size*sizeof(int));
  mid = max_size/2;
  top = mid;
  bot = 0;
  
  for(int i=bot;i<top;i++){
    if(){
      
    }else{
    }
  }
  
}
void merge_sort(int vector[], int max_size){
  int mid;
  if(max_size > 1){
    mid = max_size/2;
    merge_sort(vector, mid);
    merge_sort(vector + mid, max_size - mid);
    merge(vector, max_size);
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
  merge_sort(vector, max_size);
  print_vector(vector, max_size);
  return 0;
}
