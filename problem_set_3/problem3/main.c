#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

int main()
{
    char word[100];
    char *definition;
//calling of the load_dictionary funtion which contains the words defined with their meaning 
    load_dictionary();
//ask user to enter for any word they want to get its meaning 
    printf("Enter a word to look up (or type 'quit' to exit): ");
    while (1) {
        scanf("%s", word);
//if quit is entered the program stops or quits
        if (strcmp(word, "quit") == 0)
            break;
//if the word is contained in the dictionary give its defination elseteel user that the word is not found
        definition = lookup(word);

        if (definition != NULL)
            printf("Definition: %s\n", definition);
        else
            printf("Word not found in the dictionary.\n");

        printf("Enter another word to look up (or type 'quit' to exit): ");
    }

    return 0;
}
