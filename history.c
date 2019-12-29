#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
    List *history = (List*) malloc(sizeof (Item) * 100);
    return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List* list, char* str){
    Item *node = list->root;
    int id = 1;
    if (node == NULL) {
        list->root = (Item*) malloc(sizeof (Item));
        list->root->id = id;
        list->root->str = str;
        list->root->next = NULL;
    }
    else {
        id++;
        while (node->next != NULL) {
            node = node->next;
            id++;
        }
        node->next = (Item*) malloc(sizeof (Item));
        node->next->id = id;
        node->next->str = str;
        node->next->next = NULL;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char* get_history(List* list, int id){
    Item *node = list->root;
    while (node != NULL) {
        if (node->id == id) {
            return node->str;
        }
        node = node->next;
    }
    return "History entry not found";
}

/* Print the entire contents of the list. */
void print_history(List* list){
    Item *node = list->root;
    while (node != NULL) {
        printf("[%d] = %s\n", node->id, node->str);
        node = node->next;
    }
}

/* Free all Items and the List. */
void free_history(List* list){
    Item* node = list->root;
    Item* temp;
    while(node != NULL){
        temp = node;
        free(node);
        node = temp->next;
    }
    list->root = NULL;
}