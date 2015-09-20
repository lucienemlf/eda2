#include <iostream>
#include <vector>
#include <stdlib.h>
#include "double_list.h"

void radomlist(List* list){
  insert(list,15);
  insert(list,6);
  insert(list,22);
  insert(list,12);
  insert(list,36);
  insert(list,49);
  insert(list,20);
  insert(list,18);
  insert(list,6);
  insert(list,15);
  insert(list,20);
  insert(list,11);
  insert(list,4);
}

int main(){
  List* list = NULL;
  list = init();
  radomlist(list);
  print_list(list);
  cout << endl;
  return 0;
}
