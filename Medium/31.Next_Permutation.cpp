class Solution {
public:
    void reverse(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    int findSwap(vector<int>& nums, int start, int end, int num)
    {
        for(int i = end; i >= start; i--)
        {
            if(num < nums[i])
            {
                return i;
            }
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        
        int size = (int)nums.size();
        for(int i = size - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                int swap = findSwap(nums, i + 1, size - 1, nums[i]);
                int tmp = nums[i];
                nums[i] = nums[swap];
                nums[swap] = tmp;
                reverse(nums, i + 1, size - 1);
                return;
            }
        }
        reverse(nums, 0, size - 1);
    }
};