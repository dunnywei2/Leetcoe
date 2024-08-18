->question needs to go through
1), 20), 21), 121), 125),226), 242), 704), 733), 53), 235) 110), 141) ->First week

->questions for second week
232) 278) 383) 70) 409) 206) 169) 67) 543) 876) 104) 217)


->hash table in C->https://www.bilibili.com/video/BV1fr4y1i7Px/?spm_id_from=333.337.search-card.all.click&vd_source=352d86e561ef82fd069e1251bfae8933
->in C->https://github.com/vli02/leetcode/blob/master/1.%20Two%20Sum.c
->serach terms->两数之和 哈希表 C
->explaination
    https://leetcode.com/problems/two-sum/solutions/189807/c-c-python-ts-js-java-various-solutions-c-is-o-n-time-and-just-6-lines-c-hashmap-solution/
->
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


----------------------------------------------------------------------------
   #if 1
typedef struct data_s {
   int val;
   int idx;
} data_t;
int cmp(const void *a, const void *b) {
    return ((data_t *)a)->val - ((data_t *)b)->val;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *return_array=(int*)malloc(2 * sizeof(int));
    *returnSize=2;
    return_array[0]=0;
    return_array[1]=1;
   
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
      
    }

    for(i=0,j=numsSize - 1;i<j;)
    {
        printf("within for loop %d %d\n",i,j);

            printf("array[i].val is %d i is %d \n",array[i].val,i);
            printf("array[j].val is %d j is %d \n",array[j].val,j);


        if((array[i].val+array[j].val)==target)
        {
            return_array[0]=array[i].idx;
            return_array[1]=array[j].idx;
            printf("return_array[0] is %d \n",return_array[0]);
            printf("return_array[1] is %d \n",return_array[1]);
            break;
        }
        else if((array[i].val+array[j].val)<target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return return_array;
}

#else

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    result[0] = 0;
    result[1] = 1;
    return result;
}

#endif
