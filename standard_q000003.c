/*
 *->https://www.geeksforgeeks.org/window-sliding-technique/
 *->https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *->about set->https://www.youtube.com/watch?v=682xT_TcKUg
 *->https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/3.%20Longest%20Substring%20Without%20Repeating%20Characters.cpp
 *->https://www.interviewbit.com/blog/longest-substring-without-repeating-characters/
 *->shift array in C->https://stackoverflow.com/questions/55399500/c-array-how-can-i-shift-each-character-in-a-string
 *in C++->https://www.youtube.com/watch?v=RqxIXM6eyiY&pp=ygUebGVldGNvZGUgIzMgbG9uZ2VzdCBzdHJpbmcgQysr
 *in C->https://github.com/vli02/leetcode/blob/master/3.%20Longest%20Substring%20Without%20Repeating%20Characters.c
 *more relate to C video->https://www.youtube.com/watch?v=F5diwvtLirU
 */

#include <string>
#include <sstream>
class Solution {
protected:

public:
#if 0
    //brute force way
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
                   printf("find duplicate and go i is %d and j is %d \n",i,j);
                } 
            }

        }

       
        return ans;
    }
#endif

//windows method in C++
      int lengthOfLongestSubstring(string s) {
      std::set<char> Set;
        int max=0;
        int start=0;
        int end=0;

        while(end<s.size())
        {
            // std::cout<<"end is"<<end<<std::endl;
            auto iter=Set.find(s[end]);

            if(iter==Set.end())
            {
                //unique one
                int tnumber=end-start+1;
                if(tnumber>max)
                   max=tnumber;
                std::cout<<"max "<<max <<" start " <<start <<" end "<<end<<std::endl;
                Set.insert(s[end]);
                end++;
            }
            else
            {
                //find the repitition pattern
                std::cout<<"repieittion max "<<max <<" start " <<start <<" end"<<end<<std::endl;

                Set.erase(s[start]);
                start++;
            }
            
        }         
       
        return max;
    }

};

//FOR C
int lengthOfLongestSubstring(char * s){
    int length=strlen(s);
    // printf("length %d \n",length);

    int i,j,l,k=0;
    int n=0;
    //n->tracking number of continous chracters without repeating
    char c;//to find out the ASCII of any string
    int pos[128]={0}; //128 entries in ASCII table
    
    
    
    for(int i=0;i<length;i++)
    {
       n++;
       c=s[j];

       l=i-pos[c]+1;
       printf("l : %l, i: %i, c is %c, pos[c] is %d, n is %d \n",l,i,c,pos[c],n);
    }
    , 
    return 0;   
}

    
    
    //using "pwwkew"
//First letter p->    line 24 "return false"-> line 34-> if(true)->line 37->comparing 'p' and '_'->count_substring=1
//Second letter w->   line 24 "return false"-> line 34-> if(true)->line 37->comparing 'w' and '_'->count_substring=2
//third letter w->   line 20 "return true"-> line 44-> else->line 45>count_substring=0

//"pwwkew"
//i=0 as p, j=0 as p->chars->"p"->return true->max is 1
//i=0 as p, j=2 as w->chars->"pww"->return false->no max
//i=0 as p, j=3 as k->chars="pww"->return false->no max->can't continue since it will always get blocked in j=2, IMPORTANT

//test case a) as
a b c a b c b b
0|1|2|3|4|5|6|7
