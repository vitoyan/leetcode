/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * algorithms
 * Easy (31.46%)
 * Total Accepted:    189.7K
 * Total Submissions: 603K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */


public class Solution {
        public String longestCommonPrefix(String[] strs) {
            if(strs == null || strs.length == 0)
                 return "";
            StringBuilder result = new StringBuilder();
            boolean flag = true;
            while(flag)
            {
                int index = result.length();
                for(int i = 0; i < strs.length;i++)
                {
                    if(index >= strs[i].length() || strs[0].charAt(index) != strs[i].charAt(index))
                    {
                        flag = false;
                        break;
                    }                
                }
                if(flag)
                    result.append(strs[0].charAt(index));
            }
            return result.toString();
                                      
        }
}




