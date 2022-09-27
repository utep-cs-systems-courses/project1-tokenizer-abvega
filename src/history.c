#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"



List* init_history(){
    List *history = malloc(sizeof(List));
    history->root = malloc(sizeof(Item));
    return history;
}

void add_history(List *list, char *str){
    int num = 1;
    Item *temp = list->root;
    while(temp->next != 0){
        temp = temp->next;
        num++;
    }
    temp->next = malloc(sizeof(Item));
    temp->next->str = copy_str(str,lengthString(str));
    temp->next->id = num;
}
char *get_history(List *list, int id){
    Item *temp = list->root;
    if(temp == NULL){
        return NULL;
    }
    while(temp && temp->id !=id){
        temp = temp->next;
    }
    return temp->str;
}
void print_history(List *list){
    Item *temp = list->root->next;
    while(temp != 0){
        printf("%d. %s",temp->id, temp->str);
        temp = temp->next;
    }
}
void free_history(List *list){
    Item *temp = list->root;
    while(temp->next != 0){
        Item *prev = temp;
        temp = temp->next;
        free(prev->str);
        free(prev);
    }
    free(temp->str);
    free(temp);
    free(list);
}
int string_length(char *str){
    int lngth = 0;
    for(int i =0; *(str+i) != '\0'; i++){
        lngth =+1;
    }
    return lngth;
}