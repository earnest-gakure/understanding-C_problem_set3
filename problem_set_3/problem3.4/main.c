#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int main (){
   FILE * fp = NULL;

   int nfiles = __argc; /*ignore the name of the program itself*/
   int argidx = 1;     /*ignore the name of the program itself*/
   char *currfile = " ";
   char c;
   /*count of words ,lines ,characters*/
   unsigned long nw=0,nl=0,nc=0;
  bool whitespace = true;

   if (nfiles==0){
    fp=stdin;/*standard input*/
    nfiles++;

   }
   else       /*set to first*/
   {  
    currfile =__argv[argidx++];
    fp=fopen(currfile,"r");

   }
   while(nfiles>0)  /*files left>0*/
      {
        if (fp==NULL)
        {
            fprintf(stderr,"unable to open input \n");
            exit(-1);
        }
        nc=nw=nl=0;
        while((c=fgetc(fp)!=EOF))
        {
            /*TODO :FILE HERE 
            processes the file  using getc(fp)
            */
        nc++;
        if(whitespace && !isspace(c)){
            nw++;
            whitespace = false; //we have shifted to nonspace chararacters
        }
        else if (!whitespace && isspace(c))//if we were not reading a space and the new charac is a space
        {
            whitespace = true;
        }
        if(c=='\n'){
            nl++;
        }

           
            
        }
        printf("%ld %s \n",nc ,currfile);
        /*next file if exists*/
        nfiles--;
        if(nfiles>0)
        {
            currfile=__argv[argidx++];
            fp=fopen(currfile,"r");
        }
      }
    return 0;
}

