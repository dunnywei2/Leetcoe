class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<char> tBuffer;
        for(int i=0;i<s.length();i++)
        {
           if(!tBuffer.empty()){     
              std::vector<char>::iterator iter;
              iter=tBuffer.find(s[i]);
              iter=tBuffer.find(s[i]);
              if(iter!=tBuffer.end())
              {
                  return true
              }
              
           }
            if(s[i]) 
        }
        return 0;
    }
};
