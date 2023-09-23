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
struct node* delnode(struct node *head , struct node *pelement);
void freelist(struct node *head);

//global variables 
struct node *head=0 ,*newnode , *temp ;
//head =0 ;//head initialized to 0
int no = 3;//keeps track of the no of nodes
int position =1;//keeps truck of position of data being searched for
struct node *result;

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
    temp->next = newnode;//linking the nodes
    temp = newnode;      //linking the list

   }

}
temp = head ;
int end ;
puts("Enter the Data you want to add at the end:\n");
scanf("%d",&end);
addback(temp , end);//calling addback function with arguments temp and data to add
temp = head ;
 display(temp);//calling display to print all the data in the ll

 //searching for data for the linked list
 //imlimenting the search function to print position and address
 int value;//holds data user wants to search for
 puts("enter Data you want to search for :\n");
 scanf("%d",&value);//user enters data
   result = search(head ,value);  //getting the return from search function which return address of the data if found
if(result != NULL )  //if data is  found print address and its position 
{
  printf("The Data is at position : %d  address :%d\n",position,result);
}
else{
  puts("The data is not in the list\n");
}

//calling delnode to delete the node where search element was found
printf("head =%d\n",head);
 head = delnode(head ,result);//newhead is when the element is head 
puts("the new list is:");
display(head);//display the new list
printf("new head = %d\n",head);

//calling the freelist function which frees the whole list
freelist(head);
printf("new head = %d\n",head);
    return 0;
}



//function to display all the elements in the list
void display(struct node *ptrHead)
{
    //travese through the list we assgn temp head address which is passed as argument
  temp = ptrHead ; 
  while(temp != 0 ) //if not end of list print data of each node
  {
    printf("Data:%d\n",temp->data);
    printf("addres:%d\n",temp);
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
  
  temp = temp->next; //move to the next node till its found
  position++;//keep track of the no of nodes
 }
  
  return NULL;//if not in the list return null
}
//function to delete a node from the list
//the node to be deleted is the one with the searched data
//function returns updated head node
struct node* delnode(struct node *head , struct node *pelement)
{

 struct node *previous = NULL;//pointer to previous node
  temp = head ;
  //first check if the element to delete is the head node
  if (temp == pelement)
  {
   head = head->next; 
   free(temp);
   return head; //return the new address of head node
  
  }
  //if it wasn't head node traverse the list 
  while(temp->next != NULL)
  {
    if (temp == pelement)
    {
      previous->next = temp->next ;
      free(temp); //delete the node
      break;///once we get it break the loop after deletion
    }
    previous = temp ; //previous node is always bedind temp
    temp = temp->next ;//move to the next node
    
   }
return head; //return new head if element was the head

}
//function to delete the list

void freelist(struct node *head)
{
 struct node *current = head;
 struct node *next = NULL ;
  while(current != NULL)
  {
    next = current->next; //save the next node address before freeing
    free(current);//free current node
    current = next ; //move to the next node
  }
  
 //head = NULL ;//set head to null to indicate the list is empty
  puts("The linked list has been deleted");
  
}
