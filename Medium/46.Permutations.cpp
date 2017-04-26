class Solution {
public:
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
            swap(nums, index, i);
            permuteNums(result, nums, index + 1, size);
            swap(nums, i, index);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int size = (int)nums.size();
        if(size <= 0)
            return result;
        
        permuteNums(result, nums, 0, size);
        
        return result;
    }
};