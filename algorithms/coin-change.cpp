#include <stdio.h>

int main(){
  int change_owed;
  int check;
  char invisible_char;

  int count = 0;
  int num_q = 0;
  int num_d = 0;
  int num_n = 0;
  int num_p = 0;

  do{
    printf("How much change is owed (in cents)?\n");
    check = scanf("%d", &change_owed);
    do{
      scanf("%c", &invisible_char);
    }while(invisible_char != '\n');
  }while(check == 0 || !(change_owed >= 0));

  int c = change_owed;
  while(c > 0){
    while(c >=20){
      count++;
      num_q++;
      c = c - 20;
    }
    while(c >= 10){
      count++;
      num_d++;
      c = c - 10;
    }
    while(c >= 5){
      count++;
      num_n++;
      c = c - 5;
    }
    while(c >= 1){
      count++;
      num_p++;
      c = c - 1;
    }
    printf("Quarters: %d, Dimes: %d, Nickels: %d, Pennies: %d\n", num_q, num_d, num_n, num_p);
    printf("Number of coinds used= %d\n\n",count);
  }
}
