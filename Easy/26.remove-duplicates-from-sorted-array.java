/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array
 *
 * algorithms
 * Easy (35.50%)
 * Total Accepted:    249K
 * Total Submissions: 702.2K
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * 
 * 
 * For example,
 * Given input array nums = [1,1,2],
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length.
 * 
 */

class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length <= 1)
            return nums.length;
        int result = 1;
        int firstIndex = 0;
        int secondIndex = 1;
        while(secondIndex < nums.length) {
			if(nums[firstIndex] == nums[secondIndex])
				secondIndex++;
			else {
				result++;
				if((firstIndex + 1) != secondIndex)
					nums[firstIndex + 1] = nums[secondIndex];  
				firstIndex++;
				secondIndex++;
			}
		}
		return result;
    }
}
