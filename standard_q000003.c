/*
 *->https://www.geeksforgeeks.org/window-sliding-technique/
 *->https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *->about set->https://www.youtube.com/watch?v=682xT_TcKUg
 */

class Solution {
protected:
   std::vector<char> vector;
   public:
 
    bool checkVector(char tChar)
    {
        if(!vector.empty())
        {     
            
            if(std::find(vector.begin(), vector.end(), tChar)!=vector.end())
              {
                  return true;
              }
        }
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
