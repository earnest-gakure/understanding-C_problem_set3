#include <stdio.h>
#include <stdlib.h>
/*
the do-while loop can be transformed into a simple while loop. For each
of the following examples, write equivalent code using a while loop instead.
*/

 
double rand_double(){
    /*gnerate a random number in [0,1]*/
    double ret = (double)rand();
return ret /(RAND_MAX+1);
}
int sample_geometric_rv(double p){
    double q;
    int n;
    do{
        q = rand_double();
        n++;
    }while (q>=p);
    return n ;
}
//using while loop

int ssample_geometric_rv(double p){
    double q;
    int n;
  while (q>=p){
     q = rand_double();
        n++;
  }
  
  return n;

}

int main(){

    printf("ret= %d\n",sample_geometric_rv(5));
    printf("rett= %d\n",ssample_geometric_rv(5));
}
