#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MASK 0x1U
int32_t shiftingL(int32_t aValue)
{
   int32_t tTemp=aValu>>24;
   int32_t tSum=0;
   int counter=0;
   while(counter<8)
   {
      tSum=0.1*(2^counter)*+(tTemp&MASK);
     counter++;
     tTemp=tTemp>>1;
   }
   printf("tSum is %d \n",tSum);
   return tSum;
}

// XXXX XXX_ XXXX XXXX XXXX XXXX XXXX XXXX
// MMMM MMM1 NNNN NNNN NNNN NNNN NNNN NNNN
// where M is decimal and N is Integer for greater number
// MMMM MMM1, where M is the decimal number. First M is decimal
float convert_to_temp(int32_t input_vall)
{
   int32_t tValue=0;
   float tSum=0;
   if(input_val&0x0010000)
   {
      //extended
     tValue=(input_val&0x001FFFF);
     int32_t tTemp=(input_val&0xFFF10000)>>24;
      float tFloat=0;
     for(int i=0;i<7;i++)
     {
        tFloat+=16*i+
     } 
      
   }  
   else{
        //standard
   } 

}

int main()
{
   shiftingL(0x03FFFFFF);

}
