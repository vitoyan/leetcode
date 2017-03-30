#include <unordered_map>
#include <cmath>

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if((int)nums.size() == 0 || k < 0)
            return 0;
            
        std::unordered_map<int, int> map;
        int count = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            map.insert({nums[i], i});
        }
        
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(map.find(nums[i] + k) != map.end() && map.find(nums[i] + k)->second != i)
            {
                count++;
                map.erase(nums[i] + k);
            }
        }
       
        
        return count;
    }
};