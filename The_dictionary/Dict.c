#include <stdio.h>
#include <string.h>
#include "dict.h"
int num_words =5;//keep track of the number of words in the dictionary
int num_of_defs= 5; //keep track of the no of definitions in the dictionary 


// initialize words defined in the dictionary 
char words_list[MAX_DEFS][MAX_LENGTH] = {
    "orange",
    "grapes",
    "phone",
    "radio",
    "pen" 
};

//an array of definitions 
char the_dictionary[MAX_DEFS][MAX_LENGTH] = {
    "A fruit that grows on orange trees.",
    "Small purple type of fruits.",
    "A gadget used for communication means.",
    "A gadget used to play music.",
    "An item used for writing."
};

//declaration and initialization of a pointer to the dictionary array 
char *dictionary_pointer=the_dictionary[0];

//declaration and initialization of a double pointer which points to dictionary_pointer
char **pointer_to_dictionary_pointer = &dictionary_pointer; // Declare and assign the address of dict_pointer


void load_dictionary() {
    // Nothing to do here since the dictionary is already defined in dict.h
}

//function to check if the entered word is defined ,if yes return words definition
char *lookup(char input_word[]) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(input_word, words_list[i]) == 0) {
            return *pointer_to_dictionary_pointer; //return the pointed to value i.e dict_pointer which hass address of the_dict[i]
        }
       (* pointer_to_dictionary_pointer)++;  // Increment the pointer to point to the next definition
    }
  
    return NULL; // Word not found
}
// a function to add the words not defined in the dictionary .the user also enters its meaning 
void add_word( char new_word [] , char new_definition [])
{
  if(num_words < MAX_DEFS){
strcpy(words_list[num_words],new_word);//copy new word to words list index[num_words] which is empyt coz 
                                       //index are counted from 0
strcpy(the_dictionary[num_words],new_definition);//copy entered definition to the_dictionary
 num_words++; //increment the count of number of words 
 num_of_defs ++; //increment definitions count                                     
  }else{
    puts("The Dictionary is full .Cannot add more words.\n");
  }

}
