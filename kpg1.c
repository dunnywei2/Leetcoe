#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    printf("Hello World");
   
    char temp[]="Hello World";
   
    int x=strlen(temp);
   
    char* temp2=(char*)malloc(sizeof(char)*(x));
   
    int j=0;
   
    for (int i=strlen(temp);i>=0;i--)
    {
        printf("i is %c \n ",temp[i]);
        temp2[j]=temp[i];
        printf("j is %c \n ",temp2[i]);

        j+=:
       
       
    }
            printf("j is %s\n",temp2);

}