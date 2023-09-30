class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> tReturn;
        int diff=0;
         std::unordered_map<int,int> tMap;
        std::unordered_map<int,int>::iterator iterator_map;
        for(int i=0;i< nums.size();i++)
        {
            diff=target-nums.at(i);
            if(iterator_map=tMap.find(diff))
            {
                   tReturn.push(iterator_map->seond);
                   tReturn.push(i);
            }else{
                tMap.push(nums.at(i));
            }   
          
        }
      return  tReturn;
    }
};
