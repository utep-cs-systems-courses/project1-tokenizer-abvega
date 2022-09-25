#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  char strng[100];
  do{
    puts(">");
    fgets(strng, 95, stdin);
    char **tokens = tokenize(strng);
    print_tokens(tokens);
    free_tokens(tokens);
  }while(1);
}

