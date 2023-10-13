class Solution {
protected:
   std::vector<char> vector;
public:

    bool checkVector(char tChar)
    {
        // if(!tBuffer.empty()){     
            
        //     if(std::find(vector.begin(), vector.end(), tChar)!=vector.end()){
        //       {
        //           return true
        //       }
              
           
        // }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        


        for(int i=0;i<s.length();i++)
        {
           
            if(this->checkVector(s[i]))
            {
                return 1;
            } 
        }
        return 0;
    }
};
