#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   char inputfile [] = "stateoutflow0708.txt";
   /*all the fields in the file*/
   char state_code_origin[100];
   char country_code_origin[100];
   char state_code_dest[100];
   char country_code_dest[100];
   char state_abbrv[100];
   char stste_name[100];
   char line_read[500];
   int return_num =0;
   int extmpt_num = 0;
   int aggr_agri = 0;
   long total=0;
   
   int fields_read =0;
  char origin_code[500] ;
   FILE *fp;
   fp=fopen("stateoutflow0708.txt","r");

   if (fp==NULL){
    printf("Error Opening the file");
    exit(1);
   }
 printf("Enter  State (1-56)Origin code :");
 gets(origin_code);
  printf("%-20s%25s\n","STATE ","TOTAL");
  printf("-----------------------------------------------\n");

   while(fgets(line_read,500,fp)){
   fields_read = sscanf(line_read,"%s%s%s%s%s%s%d%d%d",
               state_code_origin,
               country_code_origin,
               state_code_dest,
               country_code_dest,
               state_abbrv,
               stste_name,
               &return_num,
               &extmpt_num,
               &aggr_agri );



if (strcmp(state_code_origin,origin_code)==0){
   printf("%-20s%25d\n",stste_name,aggr_agri);
   total +=aggr_agri;
}
   }
printf("-----------------------------------------------\n");
 printf("%-20s%25lu\n","TOTAL",total);

fclose(fp);
    return 0;
}