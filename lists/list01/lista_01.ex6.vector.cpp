// Binary Search
#include <iostream>
#include <stdlib.h>

using namespace std;

// Binary search adding interpol method
int binary_search(int vector[], int element, int min, int max){
  int result = -1;
  while(min<=max){
    int mid = min + (max - min)*((element-vector[min])/(vector[max]-vector[min]));
    //int mid = (max-min)/2 + min;
    if(vector[mid] == element){
      result = mid;
      break;
    } else
    if(vector[mid] < element){
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }
  return result;
}

void preconfig(int vector[], int max_size){
  for(int i = 0 ; i<max_size ; i++){
    vector[i] = i*2;
  }
}

// Only for debug
void print_vector(int vector[], int max_size){
  for(int i = 0; i<max_size ; i++){
    cout << vector[i] << " ";
  }
  cout << endl;
}

int main(){
  int max_size = 0;
  cout << "Enter the max size:";
  cin >> max_size;
  int vector[max_size];
  preconfig(vector, max_size);

  int element = 0;
  cout << "Number to find: ";
  cin >> element;

  int searching = binary_search(vector,element,0,max_size-1);
  if(searching == -1){
    cout << "Element not found" << endl;
  } else {
    cout << "Element found on position " << searching << endl;
  }
  return 0;
}
