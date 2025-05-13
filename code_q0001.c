/*
 *Java->brute force
 */

class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i=0;i<nums.length;i++)
        {
           for(int j=i+1;j<nums.length;j++)
           {
                if(nums[i]+nums[j]==target)
                {
                    return new int[]{i,j};
                }
           }
        }
        return nums;
        
    }
}

/*
java hash map
*/
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>(); // A mapping to store numbers and their indices
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i]; // Find the required number to reach the target
            if (numMap.containsKey(complement)) {
                return new int[]{numMap.get(complement), i}; // Return indices of the complement and current number
            }
            numMap.put(nums[i], i); // Store the number with its index
        }
        return new int[]{}; // This line is never reached due to the problem guarantee
    }
}

/*C++ hash map*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // A mapping to store numbers and their indices
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Find the required number to reach the target
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i}; // Return indices of the complement and current number
            }
            num_map[nums[i]] = i; // Store the number with its index
        }
        return {}; // This line is never reached due to the problem guarantee
    }
};

---------------------------------------
/*my hasmap Java*?
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for(int i=0;i<numbs.length;i++)
        {
            
            int diff=target-nums[i];
            if(hashmap.contain(diff))
            {
                return new int{hashmap.get(diff),i};
            }
            else{
                hashmap.put(diff,i);
            }
        }
        
    }
}
