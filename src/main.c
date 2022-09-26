#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  char input[100];
  List *hist = init_history();
  printf("Please select 1. to tokenize words or 2. to see the history");
  fgets(input, 100, stdin);
  int select = atoi(input);
  if(select == 1){
    printf("Enter your sentence: \n");
    fgets(select, 100, stdin);
    add_history(hist, input);
    char **tokens = tokenize(input);
    print_tokens(tokens);
  }
  else if(select == 2){
    print_history(hist);
  }
}

