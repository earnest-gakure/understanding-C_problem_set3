#include <stdio.h>

//function prototypes
void shell_sort (void);
void shift_element_by_gap(unsigned int i , unsigned int gap);

//global variables 
int a[10] = {100,20,40,70,90,50,30,80,10,60};
int n=10;

int main ()
{
    //calling the shell sort function to sort the array
    shell_sort();

//printing the new sorted array
puts("The sorted array is :");
for (int i =0 ; i < n ; i++)
{
    printf("%d ",a[i]);
}
    return 0;
}


void shell_sort (void)
{
    /*sort , comparing against farther away
    elements first ,then closer element
    */
    unsigned int gap ,i;
    for( gap = n/2 ; gap >=1 ; gap = gap/2 )
    {
       //do insertion_like sort ,but comparing and 
       //sifting elements in multiple gaps
       for( i = gap ; i < n ; i++)
       {
        //check if element at gap value is less ,if yes swap
        if( a[i - gap] > a[i] )
        {
            shift_element_by_gap(i ,gap);//calling the swap function if condition is true
        }
       }
    }
}

//function to do swaping of the elements 
void shift_element_by_gap(unsigned int i , unsigned int gap)
{ 
   int temp = a[i]; //temp = value at gap
   //ensure i does not go below gap value to prevent out of bounds access
 while(i >=gap && a[i - gap ] > temp)
 {
    a[i] = a[i-gap]; //swap their values if condition true
    i = i - gap ;//shift index of i after every swap
 }
 a[i] = temp ;
}

