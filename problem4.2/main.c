/*
#include <stdio.h>
#include <string.h>

//functions prototype
//char *pnexttoken;
//char *strtok(char *text , const char * delims);

char *str = "this is a bag.";
char *delimiter = " ";
char *ch = "this a";
int main ()
{
    //strspn function computes the index of the first non-delimiter 
    //character in our string 

   int spn = strspn(str , ch);
   printf("spn index: %d\n",spn);
  
  //*strcspn function returns the index of the 1st occurence of
  delimiter character from the string 
  //
   int cspn = strcspn(str , delimiter);
   printf("cspn index :%d\n",cspn);
    return 0;
}












char *strtok(char *text , const char * delims)
{
    //initialize
    if(!text)
    text = pnexttoken ;

    //find start of the token in text 
     text += strspn(text , delims);

     if(*text == '\0')
     return NULL;
     
     //find end of token in the text
     pnexttoken = text + strcspn(text , delims);

     //insert null-terminator at end 
     if (*pnexttoken != '\0')
     *pnexttoken++ = '\0';
     return text;
     

}
*/

#include <stdio.h>
#include <string.h>

char *pnexttoken = NULL; // Global variable to maintain state between calls

char *strtok(char *text, const char *delims) {
    // Initialize
    if (!text)
        text = pnexttoken;

    // Find the start of the token in text
    text += strspn(text, delims);

    if (*text == '\0')
        return NULL;

    // Find the end of the token in the text
    pnexttoken = text + strcspn(text, delims);

    // Insert a null-terminator at the end to terminate the current token
    if (*pnexttoken != '\0')
        *pnexttoken++ = '\0';

    return text;
}

int main() {
    char input[] = "This is a sample string,tokenized by spaces and commas";
    const char delimiters[] = " ,"; // Delimiters are space and comma

    // Initial call to strtok with the input string
    char *token = strtok(input, delimiters);

    // Keep calling strtok until it returns NULL
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}
