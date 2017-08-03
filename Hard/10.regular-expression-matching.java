/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching
 *
 * algorithms
 * Hard (24.07%)
 * Total Accepted:    143.8K
 * Total Submissions: 597.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "a*") ? true
 * isMatch("aa", ".*") ? true
 * isMatch("ab", ".*") ? true
 * isMatch("aab", "c*a*b") ? true
 * 
 */
public class Solution {
    public boolean isMatch(String s, String p) {
        if(s == null || p == null)
            return false;
        boolean[][] m = new boolean[s.length() + 1][p.length() + 1];
        m[0][0] = true;
        for(int i = 1; i < p.length() + 1; i++)
        {
            if(p.charAt(i - 1) == '*')
            {
                if(m[0][i - 1] || (i > 1 && m[0][i - 2]))
                    m[0][i] = true;
            }
        }
        
        for(int i = 1; i < s.length() + 1; i++)
            for(int j = 1; j < p.length() + 1; j++)
            {
                if(s.charAt(i - 1) == p.charAt(j - 1))
                    m[i][j] = m[i - 1][j - 1];
                if(p.charAt(j -1) == '.' )
                    m[i][j] = m[i - 1][j - 1];
                if(p.charAt(j - 1) == '*')
                {
                    if(s.charAt(i - 1) != p.charAt(j - 2) && p.charAt(j - 2) != '.')
                    {
                        m[i][j] = m[i][j - 2];
                        
                    }
                    else
                    {
                        m[i][j] = (m[i][j - 2] | m[i][j - 1] |  m[i - 1][j - 1] | m[i - 1][j]);
                    }
                }
            }
        
        return m[s.length()][p.length()];        
    }
}
