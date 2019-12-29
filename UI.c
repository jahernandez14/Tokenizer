#include<stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define TRUE 1

char* copyString(char* str);

int main () {
    printf("******************Tokenizer******************\n\tCommands:\n\t!h - Print history\n\t");
    printf("![number] - tokenize specific entry\n\t!f - Free all history entries\n\t!q - Quit\n");
    List *history = init_history();
    while(TRUE) {
        char str[256];
        printf( ">" );
        fgets (str, 256, stdin );
        if(str[0] == '!' && (str[1]== 'h' || str[1]=='H')){
            print_history(history);
        }
        if(str[0] != '!') {
            char *copy = copyString(str);
            add_history(history, copy);
        }
        if(str[0] == '!' && str[1] > 48 && str[1] < 58){
            int x = atoi(str+1);
            char* token = get_history(history, x);
            char** tokenized = tokenize(token);
            print_tokens(tokenized);
            free_tokens(tokenized);
        }

        if(str[0] == '!' && (str[1] == 'f' || str[1] == 'F')){
            free_history(history);
        }

        if(str[0] == '!' && (str[1] == 'q' || str[1] == 'Q')){
            printf("Session will now terminate\n");
            break;
        }
    }
        return 0;

}

char* copyString(char* str){
    char *copy = (char*)malloc(sizeof(char) * (string_length(str)));
    int j = 0;
    for(j=0; j < string_length(str);j++){
        if (str[j] != '\0' && str[j] != '\n'){
            copy[j] = str[j];
        }
    }
    return copy;
}