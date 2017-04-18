class Solution {
public:
    int minInNums(vector<int>& nums, int start, int end)
    {
        int result = nums[start];
        for(int i = start; i <= end; i++)
        {
            if(result > nums[i])
                result = nums[i];
        }
        return result;
    }
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int start = 0;
        int end = (int)nums.size() - 1;
        int middle = 0;
        while(nums[start] >= nums[end])
        {
            if(end - start == 1)
            {
                middle = end;
                break;
            }
            middle = (start + end)/2;
            if(nums[start] == nums[middle]
            && nums[middle] == nums[end])
                return minInNums(nums, start, end);
            if(nums[middle] >= nums[start])
                start = middle;
            else if(nums[middle] <= nums[end])
                end = middle;
        }
        
        return nums[middle];
    }
};