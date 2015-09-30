#include<iostream>

void counting_sort(int counting[], int list[], ){

  int list_size = sizeof(list)/4;
  int count_size = sizeof(counting)/4;

  for(int i=0;i<list_size;i++){
    counting[list[i]]++;
  }
  for(int i=1; i<count_size ; i++){
  }
  for(int i=list_size-1; i>=0 ; i--){
  }
  for(int i=1; i<list_size; i++){
  }
}

void frequence(){
}

int main(){
  return 0;
}
