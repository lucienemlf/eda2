/*
Insertion Sort O(n²)
Mais eficiente quando os elementos estao ordenados.
Realiza menos trocas.
*/

#include <iostream>
#include <stdlib.h>

#define TOP_RANGE 10000
#define BOT_RANGE 10

using namespace std;

// Only works with vector structure
// Takes two positions for swaping
void swap(int vector[], int pos_a, int pos_b){
  int aux = vector[pos_a];
  vector[pos_a] = vector[pos_b];
  vector[pos_b] = aux;
}

// Insertion sort
void insertion_sort(int vector[], int max_size){
  int aux;
  for(int i = 1 ; i<max_size ; i++){
    for(int j = i ; j >= 1 && vector[j] < vector[j-1] ; j--){
      swap(vector,j,j-1);
    }
  }
}

// Alocates a random number on all vector
void preconfig(int vector[], int max_size){
  srand (time(NULL)); // Initialize random seed
  for(int i=0 ; i<max_size ; i++){
    int randm = rand() % TOP_RANGE + BOT_RANGE;
    vector[i] = randm;
  }
}

// Print vector
void print_vector(int vector[], int max_size){
  for(int i=0 ; i<max_size ; i++){
    cout << vector[i] << " ";
  }
  cout << endl << endl;
}

int main(){

  cout << "Enter the max size of the vector: ";
  int max_size = 0;
  cin >> max_size;

  int vector[max_size];
  cout << "-----------------Not sorted vector-----------------" << endl;
  preconfig(vector, max_size);
  print_vector(vector, max_size);
  cout << "-------------------Sorted vector-------------------" << endl;
  insertion_sort(vector, max_size);
  print_vector(vector, max_size);

  return 0;

}
