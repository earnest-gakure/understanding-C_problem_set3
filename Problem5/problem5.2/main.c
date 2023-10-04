///@brief in this problem we continue to study about binary trees
//operation on tree be framed as recursive

#include <stdio.h>
#include <stdlib.h>
 int count = 1;
//structure defination
struct tnode
{
    int data ;
    struct tnode *left;
    struct tnode *right;
};

//function prototypes
struct tnode * talloc(int data);
struct tnode *addnode(struct tnode *root , int data);
void preorder (struct tnode *root);
void inorder(struct tnode *root);
void postorder(struct tnode *root);
int deltree(struct tnode *root);


int main ()
{
//creating 1st node
 struct tnode *root = NULL;
 root = addnode(root , 3);
 root = addnode(root ,1);
 root = addnode(root , 0);
 root = addnode(root , 2);
 root = addnode(root , 8);
 root = addnode(root , 6);
 root = addnode(root , 5);
 root = addnode(root , 9);
 
 int val;
 do
 {
  puts("\nEnter 0:preorder , 1:inorder , 2:deltree");
  scanf("%d",&val);
    switch (val)
    {
    case 0:
     puts("preorder :");
     preorder(root);  //printing elements in preorder traversal
      break;
    case 1:
    puts("\nInorder:");
     inorder(root);
     break;
     case 2:
       count = deltree(root);
      printf("\nelements deleted are :%d\n",count);
    default:
    puts("Value not defined in any case");
      break;
    }
 } while (val < 3);
 

 //puts("\n Postorder: ");
 //postorder(root);

  
 
    return 0;
}

//function to add new node to the binary tree with the given data
struct tnode * talloc(int data)
{
  struct tnode *newnode ;
  newnode = (struct tnode*)malloc(sizeof(struct tnode));

  //check if memor was allocated successfully
  if (newnode == NULL)
  {
    puts("Error allocating memeory.");
  }
  else
  {
    newnode->data = data ;
    newnode->left = NULL;
    newnode->right = NULL;
  }
  
  return newnode;
}
//add node function to insert data to the tree
struct tnode *addnode(struct tnode *root , int data)
{
  //termination condition
  if (root == NULL)
  {
    //allocate node
    //return new root
  return talloc(data);
  }
  //if data entered is less that in root go left node ele right
  //recursive call to addnode function
  else if (data <= root->data)
  {
    root->left = addnode(root->left ,data);
  }
  else
  {
    root->right = addnode(root->right , data);
  }
   
  return root ;
}
//preorder function to display the elements using preorder traversal
// ROOT LEFT RIGHT
void preorder (struct tnode *root)
{
    //termination condtion
    if (root == NULL){ return ; }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//function to print elements using inorder traversal
//LEFT ROOT RIGHT
void inorder(struct tnode *root)
{
  if (root == NULL){return ;}
  inorder(root->left);
  printf("%d " , root->data);
  inorder(root->right);  
} 
//function to display elements using postorder traversal
//LEFT RIGHT ROOT
void postorder(struct tnode *root)
{
    if (root == NULL){ return ; }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    
}
//function to delete elements in the tree using post order traversal
//returns no of elements deleted
int deltree(struct tnode *root)
{
    int nodesDeleted ;
   //base case ;empty tree ,no node to be deleted
    if (root == NULL)
    {
        return 0; //tree is already empty
    }

  //post order traversal
    nodesDeleted = deltree(root->left) + deltree(root->right) + 1;
   //free current root node
    free(root);
    return nodesDeleted;
}
