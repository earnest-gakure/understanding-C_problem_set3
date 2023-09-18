

#include <stdio.h>
#include <string.h>
#include "dict.h"

int main()
{
 char word[30];

//calling of the load_dictionary funtion which contains the words defined with their meaning 
    load_dictionary();
    puts("--------------------------");
    puts("A simple Dictionary .\n");
    puts("--------------------------");

//ask user to enter for any word they want to get its meaning 
    puts("Enter a word to look up (or type 'quit' to exit): ");
    while(1){
        scanf("%s", word);
        if (strcmp(word,"quit")==0){
     
            break;
        }
//if the word is contained in the dictionary give its defination else  tell user that the word is not found
       char *definition=lookup(word);  //word entered by user is passed as an argument to look up function
                                 //which returns pointer
     
        if (definition != NULL){
            printf("Definition: %s\n", definition);
    }else{
            puts("Word not found in the dictionary.\n");
  // lets ask the user to add a definition for this word for it to be added in dict
  char new_definition[MAX_LENGTH];
  scanf("%s",new_definition);

  //add the new words definition to the dictionary
  add_word(word,new_definition);
  printf(" '%s' has been added to the dictionary.\n",word);
    }
        puts("Enter another word to look up (or type 'quit' to exit): ");
    
    }
    return 0;
}

