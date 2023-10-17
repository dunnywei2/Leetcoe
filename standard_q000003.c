/*
 *->https://www.geeksforgeeks.org/window-sliding-technique/
 *->https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *->about set->https://www.youtube.com/watch?v=682xT_TcKUg
 */

class Solution {
protected:
   std::set<char> tVector;
   char pValue;
   public:
 
    bool checkVector(char tChar)
    {
            
         if(std::set<char>::iterator iter=tVector.find(tChar);iter!=tVector.end())
         {
              pValue=*iter;
              return true;
         }
        pValue='\0';
        tVector.insert(tChar);
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        
       int count_substring=0;


        for(int i=0;i<s.length();i++)
        {
           
            if(!this->checkVector(s[i]))
            {
               if(pValue!=s[i])
                   count_substring++;
               else
                  count_substring=0;
            } 
        }
        return count_substring;
    }
};
