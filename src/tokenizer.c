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
    return str;
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
    int words = count_words(str);
    char** tokens = malloc((words+1));
    char *p = str;
    int i;
    for(i = 0; i < words; i++){
        p = word_start(p);
        int length = lengthWord(p);
        tokens[i] = copy_str(p, length);
        p = word_terminator(p);
    }
    tokens[i] = 0;
    return tokens;
    }
    void print_tokens(char **tokens){
        while(tokens != '\0'){
            printf("%s \n",tokens);
            tokens++;
        }
    }
    void free_tokens(char **tokens){
        for(int i =0; tokens[i] != 0; i++){
            free(tokens[i]);
        }
        free(tokens);
    }
    int lengthWord(char *str){
        int lngth =0;
        for(int i =0; *(str+i) != '\0'; i++){
            if(non_space_char(*(str+i))){
            lngth+= 1;
            }
        }
        return lngth;
    }
    int lengthString(char *str){
        int lngth =0;
        for(int i =0; *(str+i) != '\0'; i++){
            if(non_space_char(*(str+i))){
                lngth+=1;
            }
        else{
            break;
        }
      }
      return lngth;
    }

