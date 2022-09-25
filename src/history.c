#include "history.h"
#include "stdio.h"


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
    temp->next->str = copy_str(str,string_length(str));
    temp->next->id =num;
}
char *get_history(List *list, int id){
    Item *temp = list->root;
    while(temp!=0){
        if(temp->id == id){
            return temp->next;
        }
    }
    return "Item not found";
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