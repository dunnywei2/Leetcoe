class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> tReturn;
        int diff=0;
         std::unordered_map<int,int> tMap;
        for(int i=0;i< nums.size();i++)
        {
            diff=target-nums.at(i);
            if(tMap.find(diff))
            {

            }else{
                tMap.push(nums.at(i));
            }   
          
        }
      return  tReturn;
    }
};
