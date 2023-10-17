/*
 *->https://www.geeksforgeeks.org/window-sliding-technique/
 *->https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *->about set->https://www.youtube.com/watch?v=682xT_TcKUg
 */

class Solution {
protected:
   std::set<char> tVector;
   public:
 
    bool checkVector(char tChar)
    {
            
         if(std::set<char>::iterator iter=tVector.find(tChar);iter!=tVector.end())
         {
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
                count_substring++;
            } 
        }
        return count_substring;
    }
};
