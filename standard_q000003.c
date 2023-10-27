#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <set>
void context_grep(int argc, char **argv, int context, char *expr)
{
   std::set<std::string> str;
   
   int each_array=strlen(argv[0]);
   printf("argv_length_col is %d \n",each_array);
   
   for(int i=0;i<7;i++)
   {
       int complex_index=0;
      
        int length=strlen(argv[i]);
        printf("argv %d with i %d %s \n",strlen(argv[i]),i,argv[i]);
        

   }
  
}


int main()
{
    char *argv[] = {
    "Hello world",
    "Welcome to California",
    "Goodbye",
    "Big sky",
    "Nice job",
    "Blue sky",
    "Hey Joe"
    };
    context_grep(6, argv, 2, "sky");
}
