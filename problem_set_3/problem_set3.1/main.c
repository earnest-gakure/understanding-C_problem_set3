#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 25
static unsigned int result_buffer[NMAX];
void fibonacci ()
{
    /*here are the variables to set as registers*/
    register unsigned int a = 0;
    register unsigned int b  = 1;
    register unsigned int c;
    register int n;

    /*do not edit below this line*/
    result_buffer[0] = a;
    result_buffer[1] = b;

    for (n = 2;n<NMAX ; n++){
        c = a +b;
        result_buffer[n]=c; /*store code in results buffer*/
       a = b;
       b = c;

    }
}
int main()
{
    int n,ntests =10000000 ;
    clock_t tstart ,tend;
    double favg,totaltime;
    /*do profilling*/
    tstart = clock();
    for(n = 0;n<ntests ;n++)
        fibonacci();
        tend = clock();
        /*end profiling*/

        /*compute averange execution time in milliseconds*/
        favg = ((double )(tend - tstart))/CLOCKS_PER_SEC/ntests;
    
        totaltime= favg;
        /*printing avg execution time in milliseconds*/
        printf("Avg execution time : %f msec\n",totaltime*1000);

    return 0;
}
