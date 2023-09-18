#ifndef _DICT_H_
#define _DICT_H_

#define MAX_LENGTH 300
#define MAX_DEFS 1000
extern int num_words;//declare num_words as an external variable
extern int num_of_defs;

void load_dictionary();
char *lookup(char input_word[]);
void add_word( char new_word [] , char new_definition []);
#endif 

