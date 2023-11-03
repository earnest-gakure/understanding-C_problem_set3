//implimenting hash tables
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUCKET 1000
#define MULTIPLIER 31
#define MAX_LEN 100

//defining a structure
struct wordrec
{
    char *word;
    unsigned long count ;
    struct wordrec* next;
};
//function to create a new node
struct wordrec* walloc(const char *str);
//hash bucket 
struct wordrec* table[MAX_BUCKET]; /*an array of structure variable*/

/*function hashing 
  it produces hash code for a string  
  multipliers 31,35 works well*/
unsigned long hashstring(const char *str);

/*function lookup
it returns pointer to the word  or creates  it if required*/
struct wordrec* lookup(const char *str , int create);

//function to clear table 
void cleartable (void );

int main(int argc , char* argv[])
{
   FILE *fp = fopen("book.txt" , "r");
   char word[1024] ;/*big enough*/
   struct wordrec* wp = NULL ;
   int i = 0 ;

  //using memeset function to initialize table to 0
  memset(table , 0 ,sizeof(table)); 
  while (1)
  {
    if (fscanf(fp ,"%s" , word) != 1)
    break;
    wp =  lookup(word , 1) ;  /*create if it doesn`t exist*/
    wp->count ++;
    
  }
  fclose(fp);

  /*print all words that have frequency  > 100*/
  for (i = 0 ; i < MAX_BUCKET ; i ++)
  {
    for (wp = table [i] ; wp != NULL ; wp = wp->next)
    {
        if(wp->count >1000)
        {
            printf("%s--> %ld \n", wp->word ,wp->count);
        }
    }
  }
  cleartable();
    return 0 ;
}
struct wordrec* walloc(const char *str)
{
 //dynamically allocating memory for each node created
 struct wordrec* p = (struct wordrec*)malloc (sizeof(struct wordrec));
 if (p == NULL)
 {
    puts("Error allocating Dynamic memory");
 }else
 {
    p->count = 0;
    p->word = _strdup(str); /*creates a duplicate of str*/
    p->next = NULL ;
 }
 return p;
}
unsigned long hashstring(const char *str)
{
    unsigned long hash = 0 ;
    while (*str)
    {
        hash = hash * MULTIPLIER + *str ;
        str++;
    }
    return hash % MAX_BUCKET ;
}
struct wordrec* lookup(const char *str, int create)
{
    unsigned long hash = hashstring(str); /*starting point*/
    struct wordrec* wp = table[hash];
    struct wordrec* curr = NULL;

    /*code to follow the linked list to find str 
      if found return pointer */
    for (curr = wp; curr != NULL; curr = curr->next)
    {
        if (strcmp(curr->word, str) == 0)
            return curr;
    }

    // If the word is not found and create is true, create a new node
    if (create)
    {
        curr = walloc(str);
        curr->next = wp;
        table[hash] = curr;
    }

    return curr;
}

void cleartable()
{
    struct wordrec* wp = NULL , *p= NULL;
    int i = 0 ;
    for(int i = 0 ; i < MAX_BUCKET ; i++)
    {
        wp =  table[i];
        while(wp)
        {
            p = wp;
            wp = wp->next;
            free(p->word);
            free(p);
        }
    }
}