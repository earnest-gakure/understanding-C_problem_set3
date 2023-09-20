#include <stdio.h>
#include <stdlib.h>




//structure declatation 
struct node {
    int data ;
    struct node *next ; //pointer to the next node
};

//function prototypes
void display(struct node *ptrHead);
struct node* addback(struct node *head , int data);
struct node *search(struct node *head , int value);


//global variables 
struct node *head=0 ,*newnode , *temp ;
//head =0 ;//head initialized to 0
int no = 3;//keeps track of the no of nodes
int position =1;//keeps truck of position of data being searched for
int main()
{
//loop for wting data to three nodes
for(int i =0 ; i<no ; i++)
{
   newnode =(struct node *) malloc(sizeof(struct node));
   puts("Enter data :");
   scanf("%d",&newnode->data);
   newnode->next =0 ; //we assume this is the last node in every loop

   if( head == 0)
   {
    head = temp = newnode;
   }
   else
   {                                                                          
    temp->next = newnode;
    temp = newnode;

   }

}
temp = head ;
int end ;
puts("Enter the Data you want to add at the end:\n");
scanf("%d",&end);
addback(temp , end);
temp = head ;
 display(temp);

 //searching for data for the linked list
 //imlimenting the search function to print position and address
 int value;
 puts("enter Data you want to search for :\n");
 scanf("%d",&value);
struct node *result = search(head ,value);
if(result != NULL )
{
  printf("The Data is at position : %d  address :%p\n",position,*result);
}
else{
  puts("The data is not in the list\n");
}


    return 0;
}



//function to display all the elements in the list
void display(struct node *ptrHead)
{
    //travese through the list we assgn temp head address
  temp = ptrHead ; 
  while(temp != 0 ) //if not end of list print data of each node
  {
    printf("Data:%d\n",temp->data);
    temp = temp->next ; //linking the nodes in the list
  }
}
//function to add data to the end of the list
struct node* addback(struct node *head , int data)
{
  //dynamic memory allocation for newnode
   newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data = data; //asigning newnode data to data argument
   newnode->next = 0; //since this will be our last node

   //traverse the list to add the new node
   temp = head ;
   while(temp->next!= 0)
   {
    temp = temp->next ;
   }
   temp->next = newnode; //linking the nodes 

return head ;

}
//function to search for data from the linked list
struct node *search(struct node *head ,int value)
{
  temp= head ; //temp is at start of list
 
 while (temp != 0)
 {
  if( value == temp->data)
  {
    return temp ;//return address of the node 
  }
  
  temp = temp->next; //move to the next node 
  position++;//keep track of the no of nodes
 }
  
  return NULL;//if not in the list return null
}