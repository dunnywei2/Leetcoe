
// XXXX XXX_ XXXX XXXX XXXX XXXX XXXX XXXX
// MMMM MMM1 NNNN NNNN NNNN NNNN NNNN NNNN
// where M is decimal and N is Integer for greater number
// MMMM MMM1, where M is the decimal number. First M is decimal
float convert_to_temp(uint32 input_vall)
{
   uint32 tValue=0;
   float tSum=0;
   if(input_val&0x0010000)
   {
      //extended
     tValue=(input_val&0x001FFFF);
     int32 tTemp=(input_val&0xFFF10000)>>24;
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
