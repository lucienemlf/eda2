// Com base no codigo da busca sequencial, evolua o
// código para uma busca sequencial com índice primário.

#include <iostream>
#include <string>
#define MAX 20
#define INDEX 5

using namespace std;

typedef struct index
{
	int position;
	int value;
}Index;


int search(int vector[], int element, int position){
  int result = -1;

  cout << endl << "Position " << position << endl;
  for(int i = position; i<MAX ; i++){
    if(vector[i] == element){
      cout << "entrou no for" << endl;
      result =  i;
    }
  }
  return result;
}

int search_table(int vector[], Index index[], int number) {
  int i = 0;
  int result = 0;
  while(number >= index[i].value && i<INDEX){
  	i++;
  }

  cout << "I: " << i << endl;
  result = search(vector,number,index[i-1].position);
  return result;
}
void index_table(int vector[], Index index[]){
  int l = 0;
  for(int i = 0; i<INDEX ; i++) {
    index[i].value = vector[l];            // Guarda a posição do numero pertencente ao vetor
    index[i].position = l;         // Popula o posição dos valores no índice
    l+=4;
  }
}


void print(int vector[]){
  for(int i = 0; i < MAX ; i++){
    cout << vector[i] << " ";
  }
}

void print_index(Index index[]) {
  for (int i = 0; i < INDEX; ++i) {
    cout << index[i].value << " ";
  }
}


int main(){

  Index index[INDEX];
  int vector[MAX] = {1,3,12,23,46,67,87,99,120,150,160,177,182,203,230,254,311,313,369,389};
  int element = 0;

  index_table(vector,index);
  cout << "Vector " << endl;
  print(vector);
  cout << endl << "Index " << endl;
  print_index(index);

  cout << endl << "Insert the number" << endl;
  cin >> element;

  int result = search_table(vector,index,element);

  if(result == -1){
    cout << "Element not found" << endl;
  }else{
    cout << "Element found on position " << result << endl;
  }

  return 0;
}
