#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int position = 1; //keep track of numberof elements

//structure declaration
struct node {
    int data;
    struct node *next;
};

//function prototypes
void display(struct node *head);
struct node *addback(struct node *header , int data);
struct node *find(struct node *head , int data);
struct node *delnode(struct node *head ,struct node *pelement);
void freelist(struct node *head);
struct node *elements(void);


int main()
{
 struct node *head ;
 head = elements();
//calling display function
display(head);
addback(head,4); 
display(head);
struct node *result = find(head , 1);
if(result != NULL )  //if data is  found print address and its position 
{
  printf("The Data is at position : %d  address :%p\n",position,result);
}
else{
  puts("The data is not in the list\n");
}

//caling delete node function
//head is updated if dele is to the 1st node
 head = delnode(head,result);
display(head);
//freeing the lst
freelist(head );

    return 0;
}


//function to display the elememnts in the list
void display(struct node *head)
{
  struct node *temp;

  temp = head ;
  while(temp != NULL)
  {
    printf("Data:%d\n",temp->data);
    printf("Address : %p\n",temp);
    temp = temp->next ;
  }
}


//function to add element at the end of the list
struct node *addback(struct node *header , int data)
{
  struct node *newnode , *temp ;
  newnode =(struct node*) malloc(sizeof(struct node));
  if (newnode == NULL )
  {
    puts("Error adding element.Memory not allocated.");
  }
  else
  {

    newnode->data = data ;
    newnode->next = NULL ;
    if (header == NULL)
    {
       header == newnode ;//update head if list is empty 
    }else{
    
    //this loop iterates untill condition is not met
    for(temp = header ; temp->next != NULL ; temp = temp->next) { };//
        temp->next = newnode ; 
    }
  }
  return header ;

}
//function to search for an element
struct node *find(struct node *head , int data)
{
  struct node *temp ;
  temp = head ;
  while(temp != NULL)
  {
    if (data == temp->data)
    {
       return temp ;
    }
        temp = temp->next;
        position ++;
  }
  return NULL ;
}

//function to delete the node in which element was found
//returns new head incase its 1st node that is deleted
struct node *delnode(struct node *head ,struct node *pelement)
{
   struct node *temp , *previous;

   temp = head ;

   if (head == pelement)//when pelememnt is head node
   {
   head = temp->next ;
   free(temp);
    return head ;
   }
   //if pelement is not at 1st node
   while(temp->next != NULL)
   {
    if (pelement == temp)
    {
        previous->next = temp->next ;
        free(temp);
        break;
    }
    
    previous = temp;
    temp = temp->next ;
   }

   return head ;
}
//function to free the whole list
void freelist(struct node *head)
{
struct node *current , *nextnode;
  current = head ;
  while(current != NULL)
  {
    nextnode = current->next ;
    free(current);//delete current node
    current = nextnode ;//move to next node

  }
  
}
//function to create nodes and add elements
struct node *elements(void)
{
    int data ;
    struct node* head = NULL ,*temp ;

puts("Enter 3 elements:");
for ( int i = 0 ; i < 3 ; i++)
{
  struct node *newnode = (struct node* )malloc(sizeof(struct node));
  
 scanf("%d",&data);
 //check if memory has been allocated
 if (newnode == NULL)
 {
   puts("Error allocating Memory !");
 }
 else
 {
     newnode->data = data ;
     newnode->next = NULL ;
     if (head == NULL)//when this is 1st node being created
     {
       head = temp = newnode ;  
       
     }else
     {
        temp ->next = newnode ; //link the nodes
        temp = newnode;  //linking the list
     }   
 }
}

return head;
}