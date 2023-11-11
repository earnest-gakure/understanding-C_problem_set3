//how to combine union and structure to extract bit fields
//in a given data

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union packet
{
    uint32_t packetvalue ;
     struct 
     {
       uint32_t crc : 2;
       uint32_t status  : 1;
       uint32_t payload : 4 ;
       uint32_t sensor : 5;
      
     }packetfields ;
};

int main ()
{

union packet pack ;
 pack.packetvalue = 4095 ;
 
 

//print individual bit  fields
 printf("crc      :%#x\n" ,pack.packetfields.crc );
 printf("sattus   :%#x\n" ,pack.packetfields.status );
 printf("playload :%#x\n" ,pack.packetfields.payload );
 printf("sensor   :%#x\n" ,pack.packetfields.sensor );
 //check the size of the union
  printf("Size of Union is :%d\n", sizeof(pack));

  //print  packetfield bits
  printf("packetvalue:%#x\n",pack.packetvalue);

  
  
  
    return 0;
}
