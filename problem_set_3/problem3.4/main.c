#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int main ( int argc ,char * argv[]){
   FILE * fp = NULL;

   int nfiles =argc; /*ignore the name of the program itself*/
   int argidx = 1;     /*ignore the name of the program itself*/
   char *currfile = " ";
   char c;
   /*count of words ,lines ,characters*/
   unsigned long nw=0,nl=0,nc=0;
  

   if (nfiles==0){
    fp=stdin;/*fp is assigned to standard input*/
    nfiles++; //no  of file increment when input is more then 1 file

   }
   else       /*set to first*/
   {  
    currfile =argv[argidx++];
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
        while((c=fgetc(fp))!=EOF)
        {
       //   for(c=fgetc(fp);c!=EOF;c=fgetc(fp))
//{
            /*TODO :FILE HERE 
            processes the file  using getc(fp)
            */
        //when true i.e not end of file increment number of characters read 
    nc++;
    //if c is end of line increment line_count
    if(c=='\n')
    {
        nl++;
    }
    if((c==' ')||(c=='\n')) //ic c is space or end of line increment words count
    {
        nw++;

    }
       
//}
        }
        printf("no of characters =%d\n",nc);
        printf("no of words = %d\n",nw);
        printf("no of lines = %d\n",nl);
        printf("no of characters is %ld and the file is %s \n",nc ,currfile);
        /*next file if exists*/
        nfiles--;
        if(nfiles>0)
        {
            currfile=argv[argidx++];
            fp=fopen(currfile,"r");
        }
      }
    return 0;
}

