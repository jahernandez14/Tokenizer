Tokenizer Part 3 Due 10/6/19

Two classes were modified
UI.c & history.c

UI:
    UI was complete. If statements have been added to execute commands and modify history.

char* copyString(char* str);
    Helper method created to read user input during UI entries.

History:
    History was completed and implemented using a linked list.

List* init_history();
    Memory is allocated to create a history linked list.

void add_history(List* list, char* str);
    User input is read and added into the link list.

char* get_history(List* list, int id);
    Method is made to use a user ID to locate a past entry. It itirates the linked list until the desired
    ID is found. If no entry is found it will tokenize a strin that reads "Histroy Entry Not Found".

void print_history(List* list);
    This method will iterate though the linked list and print the list.

void free_history(List* list);
    Iterates through the history. Creates a temp node and frees a node one at a time.