#ifndef DICT_H
#define DICT_H

extern char *the_dictionary[1000];
void load_dictionary();
char *lookup(char word[]);

#endif // DICT_H
