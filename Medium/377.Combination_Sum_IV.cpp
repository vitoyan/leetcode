class Solution {
public:
    int combinationSum(vector<int>& nums, int target)
    {
        int result = 0;
        int* s = new int[target + 1];
        for(int i = 0; i < target + 1; i++)
            s[i] = 0;
        for(int i = 1; i < target + 1; i++)
        {
            for(auto it : nums)
            {
                if(i == it)
                    s[i]++;
                if(i - it > 0 )
                    s[i] = s[i] + s[i - it]; 
            }
        }
        
        return s[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int result = 0;
        if(nums.empty() || target < 0)
            return result;
        sort(nums.begin(), nums.end());
        result = combinationSum(nums, target);
        return result;
    }
};