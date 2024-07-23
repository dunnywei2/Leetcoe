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

#include <stdio.h>
#include <stdlib.h>

typedef struct data_s {
   int val;
   int idx;
} data_t;
int cmp(const void *a, const void *b) {
    return ((data_t *)a)->val - ((data_t *)b)->val;
}
int* twoSum(int* nums, int numsSize, int target)
{
   int *indices;
   int i, j, k;
    data_t *array;
    array = malloc((numsSize + 1) * sizeof(data_t));
    for (i = 0; i < numsSize; i ++)
    {
        array[i].val = nums[i];
        array[i].idx = i;
    }
    qsort(array, numsSize, sizeof(data_t), cmp);
    i = 0;
    j = numsSize - 1;

     for (i = 0; i < numsSize; i ++)
    {
        printf("post process array[i].value %d array[i].idx - %d \n", array[i].val, array[i].idx);
        array[i].val = nums[i];
        array[i].idx = i;
    }



#if 0
while (i < j) 
{
        k = array[i].val + array[j].val;
        if (k == target) {
            indices = malloc(2 * sizeof(int));

        indices[0] = array[i].idx;
        indices[1] = array[j].idx;
        free(array);
             return indices;
        } else if (k < target) {
            i ++;
        } else {
            j--;
        }
    }

#endif
    return 0;
}

int main()
{
    int numbs_param []={2,7,11,5};
    twoSum(numbs_param,4,18);

}
                                
