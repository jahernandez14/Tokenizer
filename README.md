Lab Project 1: Building a Tokenizer
===================================

## How to Use MakeFile
This program contain a make file. In order to use the makefile perform the following:
- Run the MakeFile by running "make" (this will compile the code and create an executable called UI
- Run UI by running "./UI"
- Run "make clean" to clean any leftover files

## How to Use Tokenizer
The purpose of this program is to create a history of entered strings. The tokenizer will keep a history
and allow the user to keep adding to the history, delete it, view history and tokenize a certain entry via
its history ID.

Commands Available:
- `!h` - Prints all history
- `!f` - Clears all history entries
- `![1-9]` - Searches an item with specified ID and tokenizes the entry
(Number entry must be between 1 and 9)
- `!q` - Terminates the program.
    