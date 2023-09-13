#include <stdio.h>
#include <string.h>
#include "dict.h"


// Define the dictionary entries with words and definitions
char words_list[MAX_DEFS][MAX_LENGTH] = {
    "orange",
    "grapes",
    "phone",
    "radio",
    "pen"
};

char the_dictionary[MAX_DEFS][MAX_LENGTH] = {
    "A fruit that grows on orange trees.",
    "Small purple type of fruits.",
    "A gadget used for communication means.",
    "A gadget used to play music.",
    "An item used for writing."
};

char *dictionary_pointer=the_dictionary[0];


void load_dictionary() {
    // Nothing to do here since the dictionary is already defined in dict.h
}

char *lookup(char input_word[]) {
    for (int i = 0; i < MAX_DEFS; i++) {
        if (strcmp(input_word, words_list[i]) == 0) {
            return dictionary_pointer;
        }
        dictionary_pointer=the_dictionary[i+1];
    }
  
    return NULL; // Word not found
}
