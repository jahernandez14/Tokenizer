Tokenizer Part 2 Due 9/29/19

One class was modified
tokenizer.c

Tokenizer:
    The tokenizer was completed and it implements all four new functions successfully.

char* copy_word(char* str);
    Alocates memory and creates a copy of a word

char** tokenize(char* str);
    This mehtod tokenizes the input word. It creates a pointer array and each array location
    has a pointer to the char array copied.

void print_tokens(char** tokens);
    This method prints all the tokens in the array. I implemented a helper method to help me with this.

void free_tokens(char** tokens);
    THis method traverses every token locations frees it then frees the main array. 


