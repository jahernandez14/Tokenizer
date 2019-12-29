#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int arrCount = 0;

/* Counts the number of characters in the string argument. */
int string_length(char* str){
   int num = 0;
   while(*str != '\0'){
       num++;
       str++;
   }
   return num;
}
/* Evaluates if the character c is an acceptable character for
   a token. Acceptable characters include any alphanumeric or
   special character. Unacceptable characters include any
   whitespace or control characters.
   Returns 0 if not, 1 if yes. */
char is_valid_character(char c){
  if(c > 32 && c<127){
    return '1';
  }
  else return '0';
}
/* Finds the next word in the string.
   For example, given an input of "  my cake" the function
   should return "my cake". */
char* find_word_start(char* str){
  while(is_valid_character(*str) == '0'){
    str++;
  }
  return str;
}

/* Finds the end of current word.
   For example, given an input of "my cake" the function
   should return " cake". */
char* find_word_end(char* str){
  while(is_valid_character(*str) == '1'){
    str++;
  }
  return str;
}

/* Counts the number of words in the string argument. */
int count_words(char* str){
  int count = 0;
  while(*str != '\0'){
    if(is_valid_character(*str) == '0'){
      str = find_word_start(str);
    }
    if(is_valid_character(*str) == '1'){
      str = find_word_end(str);
      count++;
    }
  }
  return count;
}

/* Copies the next word in str to copy. */
char* copy_word(char* str){
  int len = 0;
  str = (find_word_start(str));
  int i;
  for(i=0;is_valid_character((str[i])) != '0';i++){
      len++;
  }
  char *copy = (char*)malloc(sizeof(char) * (++len));
  for(i=0; i < len;i++){
      copy[i] = str[i];
  }
  copy[i] = '\0';
  return copy;
}

/* Tokenize the string argument into an array of tokens.
   For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */
char** tokenize(char* str){
  str = find_word_start(str);
  int count = count_words(str);
  char **copy = (char**)malloc(sizeof(char*) * count + 1);
  int i=0;
  char *temp;

  while(i< count){
      temp = copy_word(str);
      copy[i] = temp;
      str = find_word_end(str);
      str = find_word_start(str);
      i++;
  }
  arrCount = count;
  return copy;
}

/* Prints all tokens. */
void print_tokens(char** tokens){
    printf("******Tokens******\n");
    int i = 0;
    while (i < arrCount){
        printf("token [%d] = %s\n", i, tokens[i]);
        i++;
    }
}

/* Frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens){
  int i = 0;
  while (i<arrCount) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
