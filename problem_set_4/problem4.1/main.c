/*

#include <stdio.h>


void shift_element(unsigned int i);

// Declare the global array
int arr[]={2,5,6,4,3};
int main()
{
   int n=5;//aray size
   //loop for increamenting the unsorted array which will start fro A[1]
    for(int i=1;i<n;i++){
   shift_element(i);//calling the shift element function
    }
    // Print the updated array to see the result
   for(int i=0;i<n;i++)
   {
    printf("%d ",arr[i]);
   }
    return 0;

}

// Function to shift elements in the array
void shift_element(unsigned int i)
{

     int ivalue;
     for(ivalue = arr[i] ; i&& arr[i-1] > ivalue ; i--)
     {
        arr[i] = arr[i-1];
        arr[i-1] = ivalue ;
     }
}
*/
//using pointer instead of array

#include <stdio.h>


void shift_element(int *pElement);

// Declare the global array
int arr[5]={2,5,6,4,3};

   int *ptr = arr;

   int main()
{
   int n=5;//aray size
   //loop for increamenting the unsorted array which will start fro A[1]
    for(int i=1;i<n;i++){
        
   shift_element(ptr+i);//calling the shift element function
    }
    // Print the updated array to see the result
   for(int i=0;i<n;i++)
   {
    printf("%d ",*(ptr+i));
   }
    return 0;

}
void shift_element(int *pElement) {
    int ivalue;
    //pElement > ptr as a condition in the loop 
    //to ensure we don't go out of bounds of the array
    for (ivalue = *pElement; pElement > ptr && *(pElement - 1) > ivalue; pElement--) {
        *pElement = *(pElement - 1);
    }
    *pElement = ivalue;
}






