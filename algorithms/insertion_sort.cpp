/*
Insertion Sort O(n²)
Mais eficiente quando os elementos estao ordenados.
Realiza menos trocas.
*/

#include <iostream>

using namespace

void insertion_sort(){
  int i, j, aux;
  for(i = 1; i<tam;i++){
    while((j!=0)&&(v[j]<v[j-1])){
      aux = v[j];
      v[j] = v[j-1];
      v[j-1] = aux;
      j--;
    }
  }
}
