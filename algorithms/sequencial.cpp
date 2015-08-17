// Com base no codigo da busca sequencial, evolua o
// código para uma busca sequencial com índice primário.

#include <iostream>
#include <string>

#define MAX 10

using namespace std;

// Default sequencial search
int search_default(int vector[], int element){
  for(int i=0 ; i<MAX ; i++)
    if(vector[i] == element)
      return i;
  return -1;
}

// Sequencial search using sentry
int search_sentry(int vector[], int element){  
  vector[MAX+1] = element;
  for(int i=0; element!=vector[element]; i++)
    if(i<MAX+1) return i;
    else return -1;
}

// Print result
void print_result(int result, int vector[], string type){
  cout << "Type of search: " << type << endl;
  if(result == -1){
    cout << "Element not found" << endl;
  }else{
    cout << "Element " << vector[result] << " on position " << result+1 << endl;
  }
}

int main(){
  int vector[MAX+1] = {23,12,53,73,11,2,45,27,8,33};
  int element = 0;
  cout << "Insert you number: ";
  cin >> element;
  
  int result_default = search_default(vector,element);
  int result_sentry = search_sentry(vector, element);

  print_result(result_default, vector, "Default");
  print_result(result_sentry, vector, "Sentry");

  return 0;
}
