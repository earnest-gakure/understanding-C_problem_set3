//implimentiong function pointers and callback functions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaring a structure that will be used to create a class
struct student
{
    char fname[100];
    char lname[100];
    int year ;
    int age ;
};

//declaration of class of struct type
struct student class[]={
  {"Sean","Penn",2,21},
  {"Sean","Connery",4,25},
  {"Angelina","Jolie",3,22},
  {"Meryl","Streep",4,29},
  {"Robin","Williams",3,32},
  {"Bill","Gates",3,17},
  {"Jodie","Foster",4,25},
  {"John","Travolta",1,17},
  {"Isaac","Newton",2,19},
  {"Sarah","Palin",2,19}
};

/*function to compare first name and 
return 1=greater than,0=equal to ,-1=less than
 */
int compare_first_name(const void *a , const void *b);

/*function to compare last name and 
return 1=greater than,0=equal to ,-1=less than
 */
int compare_last_name(const void *a , const void *b);

/*apply function*/
void apply(struct student* sarr ,int nrec , void(*fp)(void* prec , void *arg) , void *arg);

/*function to print the students record*/
void printrec (void *prec , void *arg);

//function to print record in age order
void isolder(void *prec , void *arg);

int main()
{
    int age;
int nstudents = sizeof(class) / sizeof(struct student);
printf("no of students%d\n",nstudents);
printf("size of class:%d\n",sizeof(class));
printf("size of struct:%d\n",sizeof(struct student));


/*sorted based on first name */

puts("Sorted by first name :");
puts("---------------------------------------------");
printf("First name         Last name           age\n");
puts("---------------------------------------------");
qsort(class,nstudents,sizeof(struct student ),compare_first_name);
apply(class,nstudents,printrec,NULL);

/*sorted based on las name */
printf("\n");
puts("Sorted by last name :");
puts("---------------------------------------------");
printf("First name         Last name           age\n");
puts("---------------------------------------------");
qsort(class,nstudents,sizeof(struct student ),compare_last_name);
apply(class,nstudents,printrec,NULL);

/*print pple older than 20*/
puts("people older than 20 years :");
puts("---------------------------------------------");
printf("First name         Last name           age\n");
puts("---------------------------------------------");
    age = 20 ;
    apply(class,nstudents,isolder,&age);
    return 0 ;
}
int compare_first_name(const void *a , const void *b)
{
    struct student *sa = (struct student* )a;
    struct student *sb = (struct student* )b;
    return strcmp(sa->fname ,sb->fname);
}


int compare_last_name(const void *a , const void *b)
{
    struct student *sa = (struct student* )a;
    struct student *sb = (struct student* )b;
    return strcmp(sa->lname ,sb->lname);
}
void printrec (void *prec , void *arg)
{
    struct student* pstud = (struct student*)prec;
    printf("%-20s%-20s%2d\n",pstud->fname,pstud->lname,pstud->age);
}
void apply(struct student* sarr ,int nrec , void(*fp)(void* prec , void *arg) , void *arg)
{
    int i = 0 ;
    for (i = 0 ; i<nrec ; i++)
    {
        /*callback*/
        fp(&sarr[i] ,arg);
    }
}
void isolder(void *prec , void *arg)
{
    int *age = (int*)arg;
    struct student *pstud = (struct student*)prec;
    if(pstud->age < *age){
      return ; 
    }
      else{ 
      printf("%-20s%-20s%2d\n",pstud->fname,pstud->lname,pstud->age);
           }
}