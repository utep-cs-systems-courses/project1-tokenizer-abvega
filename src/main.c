#include <stdio.h>
#include "history.h"
int main(){
  char strng[100];
  while(1){
    putchar('$');
  while(fgets(strng,sizeof(strng),stdin)){
    fputs(strng,stdout);
    break;
  }
  }
}

