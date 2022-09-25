#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>


int space_char(char c){
    if((c == '\t' || c == ' ') && c != 0){
        return 1;
    }
    return 0;
}
int non_space_char(char c){
    if((c != '\t' || c != ' ') && c != '\0'){
        return 1;
    }
    return 0;
}
char *word_start(char *str){
    for(int i =0; *(str+i) != '\0'; i++){
        if(non_space_char(*(str + i))){
            return str+i;
        }
    }
    return *str;
}
char *word_terminator(char *word){
    for(int i = 0; *(word + i) != '\0'; i++){
        if(space_char(*(word + i))){
            return &word[0] + i;
        }
    }
    return &word[0];
}
int count_words(char *str){
    int count = 0;
    char *p = word_start(str);
    while(*p != '\0'){
        if(non_space_char(*p)){
            count+=1;
        }
        p = word_terminator(p);
        p = word_start(p);
    }
    return count;
}
char *copy_str(char *inStr, short len){
    char *copy = malloc((len+1));
    for(int i =0; i < len; i++){
        copy[i] = inStr[i];
    }
    copy[len+1] = '\0';
    return copy;
}
char **tokenize(char* str){
    char **token;
    char begin;
    char end;
    int i = 0;
    while(str != '\0'){
        if(non_space_char(str)){
            begin = word_start(str);
        }
        else if( space_char(str)){
            end = word_terminator(str);
        }
        if(begin != end){
            token[i] = end - begin;
            str+= end;
            i++;
        }
        else{
            str++;
        }
    }
    }
    void print_tokens(char **tokens){
        while(tokens != '\0'){
            puts(tokens);
            tokens++;
        }
    }
    void free_tokens(char **tokens){
        *tokens = NULL;
    }


