#include<iostream>
#include<stdlib.h>
#include"huffman.h"

using namespace std;

int main(){
  vector<Node*> heap;
  insert_heap('S',7,&heap);
  insert_heap('T',3,&heap);
  insert_heap('o',1,&heap);
  insert_heap('t',2,&heap);
  insert_heap('s',6,&heap);
  insert_heap('f',4,&heap);
  insert_heap('F',5,&heap);
  build_heap(&heap);
  cout << "---------------------------" << endl;
  print_heap(heap);
  return 0;
}
