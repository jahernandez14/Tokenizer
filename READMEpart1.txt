Tokenizer Part 1 Due 9/22/19

Two classes modified were modified.
UI.c & tokenizer.c

UI class:

The purpose of this class up to this point is to echo the input back to the user.
In addtion it will provide a ">" at the beginning of each line to signify that it is awaiting for input.
The program follows an infinite loop until it is forcefully terminated by the user.

Tokenizer:
    The tokenizer was completed and it implements all five functions successfully.

string_length
    Intakes a character pointer. The function interates and returns the total number of characters in the string_length

is_valid_character
    Intakes a single character and checks if the character is a legal character.
    It must be a number, symbol, or letter. Then returns 0 for false and 1 for true.

find_word_start
    This function is meant to traverse the string while a invalid character is detected. once the start of the string is detected it will return the pointer exclusing the incalid characters
    and will now include the start of the string.

find_word_end
    This function finds the end of the word. It intakes a character pointer and will traverse the string until it meets and invalid character and will return the new
    character pointer
count_words
    This function will use all three prior methods and interlace them to traverse the character array. every time a cycle is completed successfully it will add one to count_words
    in doing so the function will count the number of words in a given string.


