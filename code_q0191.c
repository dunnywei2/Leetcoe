#define OFFSET 0x01U
int hammingWeight(int n) {
    
    
    int input=n;
    int counter=0;
    for(int i=input;input !=0;i++)
    {
        if(input&OFFSET!=0)
        {
            counter++;
        }
        input>>=1;
    }
    printf("counter is %d \n",counter);
    return counter;   
}
