re two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

public class Solution {
    
    int findKthElement(int[] nums1, int length1, int start1, int[] nums2, int length2, int start2, int k)
    {
        if(length1 > length2)
            return findKthElement(nums2, length2, start2, nums1, length1, start1, k);
        if(length1 == 0)
            return nums2[start2 + k - 1];
        if(k == 1)
            return Integer.min(nums1[start1], nums2[start2]);
        
        int p1 = Integer.min(k/2, length1); 
        int p2 = k - p1;
        if(nums1[p1 - 1 + start1] == nums2[p2 - 1 + start2])
        {
            return nums1[p1 - 1 + start1];
        }
        else if(nums1[p1 - 1 + start1] < nums2[p2 - 1 + start2])
        {
            return findKthElement(nums1, length1 - p1, start1 + p1,  nums2, length2, start2, k - p1);
        }
        else
        {
            return findKthElement(nums1, length1, start1, nums2, length2 - p2, start2 + p2 , k - p2);
        }        
        
    }
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int s = nums1.length + nums2.length;
        if(s % 2 == 0)
        {
            return (findKthElement(nums1, nums1.length, 0, nums2, nums2.length, 0, s/2) + findKthElement(nums1, nums1.length, 0, nums2, nums2.length, 0, s/2 + 1))/2.0;
        }
        else
        {
            return findKthElement(nums1, nums1.length, 0, nums2, nums2.length, 0, s/2 + 1);
        }
        
        
    }
}
