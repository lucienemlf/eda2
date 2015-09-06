// Binary Search
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

// Binary search adding interpol method
int binary_search(int vector[], int element, int min, int max){
  int result = -1;
  while(min<=max){
    // Modification to use interpol on binary search
    //int mid = min + (max - min)*((element-vector[min])/(vector[max]-vector[min]));
    int mid = (max-min)/2 + min;
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

int main(){
  int max_size = 0; // Max size of the vector
  while(1){
    cin >> max_size;
    if(max_size==-1) break;

    int vector[max_size];
    preconfig(vector, max_size); // Creates a vector with multiples of 2
    int element = 0; // Element to find
    cin >> element;
    
    clock_t start, end;
    start = clock();
    binary_search(vector,element,0,max_size-1);
    end = clock();
    
    long double tmili = (end - start)/(double)(CLOCKS_PER_SEC/1000);
    cout << "Time: " << tmili << " ms" << endl;

  }
  return 0;
}
