/*
 *->https://www.geeksforgeeks.org/window-sliding-technique/
 *->https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *->about set->https://www.youtube.com/watch?v=682xT_TcKUg
 */

#include <string.h>
class Solution {
protected:
   std::set<char> tVector;
   char pValue;
   public:
 
    bool checkVector(char tChar)
    {
         pValue='_';         
         if(std::set<char>::iterator iter=tVector.find(tChar);iter!=tVector.end())
         {
              pValue=*iter;
              tVector.clear();
              tVector.insert(tChar);

              return true;
         }
        
        tVector.insert(tChar);
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        
       int count_substring=0;


        for(int i=0;i<s.length();i++)
        {
           
            if(!this->checkVector(s[i]))
            {
               
               if(strcmp(&pValue,&s[i]))
                  count_substring++;
               else
                   
                  count_substring=0;

            }
           else
               count_substring=1;
        }
        return count_substring;
    }
};
//using "pwwkew"
//First letter p->    line 24 "return false"-> line 34-> if(true)->line 37->comparing 'p' and '_'->count_substring=1
//Second letter w->   line 24 "return false"-> line 34-> if(true)->line 37->comparing 'w' and '_'->count_substring=2
//third letter w->   line 20 "return true"-> line 44-> else->line 45>count_substring=0

