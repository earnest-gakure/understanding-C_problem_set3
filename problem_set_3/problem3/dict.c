#include "dict.h"
#include <stdio.h>
#include <string.h>

char *the_dictionary[1000]; // Define the dictionary array

void load_dictionary()
{
    // Implement loading the dictionary data here.
    // You can read data from a file or hardcode it.
    // Example:
    the_dictionary[0] = "apple: A fruit that grows on trees.";
    the_dictionary[1] = "banana: A long, curved fruit that is yellow when ripe.";
    // Add more entries as needed
}

char *lookup(char word[])
{
    //a for loop that iteratets as far as array is not ecceded and the word entered id defined in the dictionary
    for (int i = 0; i < 1000; i++) {
        char *entry = the_dictionary[i];
        if (entry == NULL)
            break;
    //return pointer to the first occurence of colon in entry which points to the_dictionary
        char *separator = strchr(entry, ':');
        if (separator != NULL) {
            *separator = '\0'; // Null-terminate the word part
            if (strcmp(entry, word) == 0) {
                return separator + 2; // Skip space and return the definition part
            }
        }
    }

    return NULL; // Word not found
}
