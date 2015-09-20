#include<stdio.h>
#include<stdlib.h>

int main(){
  int counting[] = {0,0,0,0,0,0,0,0,0,0};
  int list[] = {3,4,1,5,6,7,7,2,3,2,3,4,4,5,1,2,3,5,8,8,1,2,4};
  int result[23];
  int list_size = sizeof(list)/4;
  int count_size = sizeof(counting)/4;

  for(int i=0;i<list_size;i++){
    counting[list[i]]++;
  }


  for(int i=1; i<count_size ;i++ ){
    counting[i] += counting[i-1];
  }

  for(int i=list_size-1; i>=0; i--){
    result[counting[list[i]]] = list[i];
    counting[list[i]]--;
  }

  for(int i=1;i<list_size;i++){
    printf("%d ",result[i]);
  }

  return 0;
}
