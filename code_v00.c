->hash table in C->https://www.bilibili.com/video/BV1fr4y1i7Px/?spm_id_from=333.337.search-card.all.click&vd_source=352d86e561ef82fd069e1251bfae8933
->serach terms->两数之和 哈希表 C
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> tReturn;
        int diff=0;
         std::map<int,int> tMap;
        std::map<int,int>::iterator iterator_map;
        for(int i=0;i< nums.size();i++)
        {
            diff=target-nums.at(i);
            iterator_map=tMap.find(diff);
            if(iterator_map!=tMap.end())
            {
                   tReturn.push_back(iterator_map->second);
                   tReturn.push_back(i);
            }else{
                tMap.insert(std::pair<int,int>(nums.at(i),i));

                // mymap.insert ( std::pair<char,int>('z',500) );
            }   
          
        }
      return  tReturn;
    }
};


/**************in C*************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int *rNumber=(int*)malloc(numsSize*sizeof(int));
    int map[128]={0};
    char character;
    
    int diff=0;
    for(int i=0;i<numsSize;i++)
    {
        diff=target-nums[i];
        
        character=diff;
        if(map[character]>0)
        {
            
        }
        else
        {
            map[character]=i+1;
            
        }    
            
        
    }
    return rNumber;
}
