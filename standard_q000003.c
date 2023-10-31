 *->https://www.geeksforgeeks.org/window-sliding-technique/
 *->https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *->about set->https://www.youtube.com/watch?v=682xT_TcKUg
 *->https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/3.%20Longest%20Substring%20Without%20Repeating%20Characters.cpp
 *->https://www.interviewbit.com/blog/longest-substring-without-repeating-characters/
 *->shift array in C->https://stackoverflow.com/questions/55399500/c-array-how-can-i-shift-each-character-in-a-string
 */

#include <string>
#include <sstream>
class Solution {
protected:

public:
    bool allUnique(string& s, int start, int end){
           set<char> chars;

        for(int i = start; i <= end; i++){
            auto res = chars.insert(s[i]);
            if(res.second == false) return false;
        }
        
        return true;
    };
    


    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(allUnique(s, i, j)){
                   printf("i is %d and j is %d \n",i,j);
                    ans = max(ans, j-i+1);
                }
                else{
                   std::stringstream snew;
                   for(int counter=i;counter<=j;counter++)
                   {
                      snew<<s[counter];
                   }
                   std::cout<<"snew"<<snew.str()<<std::endl;
                } 
            }

        }

       
        return ans;
    }
};
    
    
    
    //using "pwwkew"
//First letter p->    line 24 "return false"-> line 34-> if(true)->line 37->comparing 'p' and '_'->count_substring=1
//Second letter w->   line 24 "return false"-> line 34-> if(true)->line 37->comparing 'w' and '_'->count_substring=2
//third letter w->   line 20 "return true"-> line 44-> else->line 45>count_substring=0

//"pwwkew"
//i=0 as p, j=0 as p->chars->"p"->return true->max is 1
//i=0 as p, j=2 as w->chars->"pww"->return false->no max
//i=0 as p, j=3 as k->chars="pww"->return false->no max->can't continue since it will always get blocked in j=2, IMPORTANT
