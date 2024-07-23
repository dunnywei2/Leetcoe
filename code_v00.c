->hash table in C->https://www.bilibili.com/video/BV1fr4y1i7Px/?spm_id_from=333.337.search-card.all.click&vd_source=352d86e561ef82fd069e1251bfae8933
->in C->https://github.com/vli02/leetcode/blob/master/1.%20Two%20Sum.c
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
typedef struct _table{
   int index;
   int value;
} table;


int cmp( const void*a, const void* b)
{
    table *a_ptr= (table*) a;
    table *b_ptr=  (table*) b;
    int tmp=(a_ptr->value)-(b_ptr->value);
    return tmp;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int length=sizeof(nums)/sizeof(nums[0]);
    printf("length is %d \n",length);
    printf("numsSize is %d \n",numsSize);

    table tables[length];
    memset(tables,0,sizeof(tables));
    int rNumber=0;
    // char character;
    
    int diff=0;
    //set up hash table
    for(int i=0;i<length;i++)
    {
          tables[i].value=nums[i];
          tables[i].index=i;
    }
    //sorting the hash table
    qsort(tables,numsSize,sizeof(table),cmp);

    for(int i=0;i<length;i++)
    {
        printf("value is %d i %d \n",tables[i].value,i);
    }
    return rNumber;
}
