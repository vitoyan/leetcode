/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * algorithms
 * Easy (28.01%)
 * Total Accepted:    198.6K
 * Total Submissions: 706.2K
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */


class Solution {
    public int strStr(String haystack, String needle) {
        if(haystack == null || needle == null)
		{
			return -1;
		}
		
		int hLength = haystack.length();
		int nLength = needle.length();
		
		if(hLength < nLength)
			return -1;
		if(nLength == 0)
			return 0;
		
		for(int i = 0; i < hLength - nLength + 1; i++)
		{
			if(haystack.substring(i, i + nLength).equals(needle))
				return i;
		}
		
		return -1;        
    }
}
