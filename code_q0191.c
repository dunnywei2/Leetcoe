int main()
{
  int16_t input=0000000000000011b;
  int counter=0;
  for(int i=input;input !=0;i++)
  {
    if(input!=0)
    {
      counter++;
    }
    input>>=1;
  }
  printf("counter is %d \n",counter);
      

}
