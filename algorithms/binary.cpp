// Binary Search
#include <iostream>

#define MAX 10

using namespace std;

int binary_search(int vector[], int element, int min, int max){
  int result = -1;
  while(min<=max){
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

int main(){
  int vector[MAX] = {12,25,33,37,48,57,86,92,103,120};
  int element = 0;
  cout << "Number to find: ";
  cin >> element;

  int searching = binary_search(vector,element,0,9);
  if(searching == -1){
    cout << "Element not found" << endl;
  } else {
    cout << "Element found on position " << searching << endl;
  }
  return 0;  
}
