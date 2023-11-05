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
 *->doing in C with chinese explainayion as 力扣3 无重复字符的最长子串->https://www.bilibili.com/video/BV1rh411z7rC/?spm_id_from=333.337.search-card.all.click&vd_source=352d86e561ef82fd069e1251bfae8933
 *->another one in C++ in Chinese->https://www.bilibili.com/video/BV1GM4y1F7vn/?spm_id_from=333.337.search-card.all.click&vd_source=352d86e561ef82fd069e1251bfae8933
 *->another one for chinese explaination in general->https://www.youtube.com/watch?v=6Fprd_1_odo
 *->another one for chinese explaination ->https://www.youtube.com/watch?v=N8rJj1-j24w
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
#include  <string.h>
#include  <stdio.h>

#if 0
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
       c=s[i];

       l=i-pos[c]+1;
       printf("1st->l : %d, i: %d, c is %c, pos[c] %d, n is %d \n",l,i,c,pos[c],n);
        pos[c] = i + 1;
       printf("2nd ->l : %d, i: %d, c is %c, pos[c] %d, n is %d \n",l,i,c,pos[c],n);

       if(n>=l)
       {
           n=l;
           printf("n>=l: n %d\n",n);
       }

       if(k<=n)
       {
           k=n;
           printf("k<=n: k %d \n",n);
       }
        
    }
    
    return k;   
}
#endif

#if 0
//from others
#include  <string.h>
#include  <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int i, j, l, k = 0;
    char c;
    int pos[128] = { 0 };
    char *p;
    int n = 0;
    for (i = 0; s[i]; i ++) {
        n ++;
        c = s[i];
        l = i - pos[c] + 1;
               printf("l : %d, i: %d, c is %c, pos[c] %d, n is %d \n",l,i,c,pos[c],n);

        pos[c] = i + 1;
        n = n < l ? n : l;
        k = k > n ? k : n;
    }
    return k;
}
#endif

//my way
#include  <string.h>
#include  <stdio.h>

#define FINDMAX(a,b) (a)>(b) ?(a):(b)
int lengthOfLongestSubstring(char* s) {
    int length=0;
    int start=0;
    int max=0;
    char character;
    int map[128]={0};
    for(int i=0;i<strlen(s);i++)
    {
       
        character=s[i];

        if(map[character]>0) //repetition occurs
        {
            character=s[i];
            printf("1st length %d, start %d, character %c, map[character] %d, max %d start %d i  %d \n",length,start,character, map[character],max,start,i); 

            length=i-map[character]+1;
            start=map[character];
            max=FINDMAX(length,max);
            map[character]=i+1; //means the nth element
            printf("2nd length %d, start %d, character %c, map[character] %d, max %d start %d i  %d \n",length,start,character, map[character],max,start,i); 

        }
        else
        {
                map[character]=i+1; //means the nth element
        }
            
    }
    return max;
}

int main()
{
   // char * temp="pwwkew";
    
   char * temp="abcabcbb";
   printf("%d \n",lengthOfLongestSubstring(temp));
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

    s[0]=a
    map['a']=0+1

    s[1]=b
    map['b']=1+1

    s[2]=c
    map['c]'=2+1

    s[3]=a //repetition detect
    length=(i=3)-(old map['a']=1)+1=3
    start=1;
    max=FINDMAX(0,length)=3
    map['a']=3+1;

    s[4]=b//repetition occur
    length=(i=4)-(old map['b']=2)+1=3
    start=2
    max=FINDMAX(3,length)=3
    map['b']=4+1=5

    s[5]=c//repetition detect
    length=(i=5)-(old map['c']=3)+1=3
    1st start=2 //start is not used
    max=3
    map['c']=5+1
    2nd start=3 //start is not used
        
    s[6]=b //repitition occurs
    length=(i=6)-(old map['b'']=5)+1=2
    max=3
    map['b']=6+1=7
    
        


