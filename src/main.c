#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  List *history = init_history();
  char input[100];
  int c;
  while((c = getchar()=='\n'));
  switch(c){
    case 1:
    fgets(input,100,stdin);
    char temp = input;
    add_history(history,temp);
    char **token = tokenize(temp);
    print_tokens(token);
    free_tokens(token);
    break;
  }
}

