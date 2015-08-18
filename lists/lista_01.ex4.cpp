// Com base no codigo da busca sequencial, evolua o
// código para uma busca sequencial com índice primário.

#include <iostream>
#include <string>

#define MAX 20
#define INDEX 400

using namespace std;

int search(int vector[], int element, int position){
  cout << endl << "Position " << position << endl;
  for(int i = position; i<MAX ; i++){
    if(vector[i]==element)
      return i;
  }
  return -1;
}

void preindex(int vector[], int index[]){
  int l = 0;
  
  for(int i = 0; i<INDEX ; i++) {
    index[i] = vector[l];
    l += (MAX/INDEX);
  }
}

void print(int vector[], int size){
  for(int i=0; i<size ; i++){
    cout << vector[i] << " ";
  }
}

int search_table(int vector[], int index[], int number) {
	int i = 0;
	while(number >= index[i] && i < INDEX){
		i++;
	} 
	
	return search(vector,number,index[i-1]);
}

int main(){

  int index[INDEX];
  int vector[MAX] = {1,3,12,23,46,67,87,99,120,150,160,177,182,203,230,254,311,313,369,389};
  int element = 0;

  preindex(vector,index);
  cout << "Vector " << endl;
  print(vector,MAX);
  cout << endl << "Index " << endl;
  print(index, INDEX);

  cout << endl << "Insert the number" << endl;
  cin >> element;

  int result = search_table(vector,index,element);

  if(result!=-1){
    cout << "Element not found" << endl;
  }else{
    cout << "Element found on position " << result << endl;
  }

  return 0;
}
