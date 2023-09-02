#include <stdio.h>
#include <stdlib.h>

//(a)
int factorial(int n){
    int i,ret=1;

    for (i=2;i<=n;i++){
        ret*=i;
            }
    return ret;

}
//equivalent while loop
int while_factorial(int n){
    int j=2,rett=1;
    while(j<=n){
        rett*=j;
        j++;
    }
    return rett;
}
int main(){
    //int result;
    //result= factorial(5);
    //printf("ret= %d",result);
    printf("ret= %d\n",factorial(5));
    printf("rett= %d\n",while_factorial(5));
}
