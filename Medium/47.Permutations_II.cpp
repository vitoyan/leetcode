class Solution {
public:
    bool shouldSwap(vector<int>& nus, int begin, int end)
    {
        for(int i = begin; i < end; i++)
        {
            if(nus[i] == nus[end])
                return false;
        }
        return true;
    }
    void swap(vector<int>& nums, int m, int n)
    {
        int temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
    }
    void permuteNums(vector<vector<int>>& result, vector<int>& nums, int index, int size)
    {
        if(index >= size)
        {
            result.push_back(nums);
            return;
        }
        
        for(int i = index; i < size; i++)
        {
            if(!shouldSwap(nums, index, i))
                continue;
            
            swap(nums, index, i);
            permuteNums(result, nums, index + 1, size);
            swap(nums, i, index);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int size = (int)nums.size();
        if(size <= 0)
            return result;
        
        permuteNums(result, nums, 0, size);
        
        return result;
    }
};