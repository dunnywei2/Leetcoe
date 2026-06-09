#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
#if 1
    printf("Hello World");
   
    char temp[]="Hello World";
   
    int x=strlen(temp);
   
    char* temp2=(char*)malloc(sizeof(char)*(x+1));
   
    int j=0;
   
    for (int i=x-1;i>=0;i--)
    {
        printf("i is %c \n ",temp[i]);
        temp2[j]=temp[i];
        printf("j is %c \n ",temp2[i]);

        j++;
       
       
    }
    temp2[j]='\0';
    printf("j is %s\n",temp2);
    free(temp2)
#else
char temp[] = "Hello World";
    int x = strlen(temp);
    
    // Allocate space for the string + the null terminator
    char* temp2 = (char*)malloc(sizeof(char) * (x + 1)); 
    
    int j = 0;
    
    // Iterate from the last valid index (strlen - 1) down to 0
    for (int i = x - 1; i >= 0; i--) {
        temp2[j] = temp[i];
        j++;
    }
    
    // Append the null terminator to make it a valid C string
    temp2[j] = '\0';
    
    printf("Reversed string: %s\n", temp2);
    
    // Always free dynamically allocated memory
    free(temp2);
    
    return 0;


#endif
}