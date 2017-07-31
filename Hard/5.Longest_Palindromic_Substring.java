ven a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

public class Solution {
    public String longestPalindrome(String s) {
        if(s == null)
                return "";      
        byte[] bStr = s.getBytes();
        boolean[][] bMatrix = new boolean[bStr.length][bStr.length];
        for(int i = 0; i < bStr.length; i++)
        {
            bMatrix[i][i] = true;
        }
        int startRet = 0;
        int endRet = 0;
        for(int len = 2; len <= bStr.length; len++)
            for(int start = 0; start <= bStr.length - len; start++)
            {
                int end = start + len - 1;
                if(bStr[start] == bStr[end] && (((start + 1) >= (end - 1))|| bMatrix[start + 1][end - 1]))
                {
                    bMatrix[start][end] = true;
                    if((end + 1 - start) > (endRet + 1 - startRet)) 
                    {
                        startRet = start;
                        endRet = end;
                    }
                }
            }
        return s.substring(startRet, endRet + 1);
    }
}
