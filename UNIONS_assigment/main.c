#include <stdio.h>


union customunion{
    /// @brief defining members as bit fields 
    unsigned int intvalue: 12;  //max of 12bits OB 0000 0000 0000 
    unsigned int member1: 2 ;  //max of 2 bits OB 00
    unsigned int member2: 3 ;  //max of 3 bits OB 000
    unsigned int member3: 4 ;  //max of 4 bits OB 0000
    unsigned int member4: 3 ;  //max of 3 bits OB 000
};

int main (){

  union customunion myunion ;

  
  myunion.member1 = 3 ;  //max value it can hold  11
  printf("member1 = %u\n",myunion.member1);
   myunion.member2 = 7 ;  //max value it can hold  111
  printf("member2 = %u\n",myunion.member2);
   myunion.member3 = 15 ;  //max value it can hold   1111
  printf("member3 = %u\n",myunion.member3);
   myunion.member4 = 7 ;  //max value it can hold    111
  printf("member4 = %u\n",myunion.member4);
  
  myunion.intvalue = 4095  ;   //max value it can hold  1FFF
  printf("intvalue = %u\n",myunion.intvalue);
  
    return 0;
}