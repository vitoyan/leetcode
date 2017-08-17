/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * algorithms
 * Easy (33.31%)
 * Total Accepted:    223.5K
 * Total Submissions: 670.3K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
    public boolean isValid(String s) {
        if(s == null || s.length() <= 0)
            return true;
        Stack<Character> brackets = new Stack<Character>();
        for(int i = 0; i < s.length(); i++)
        {
            if(brackets.empty())
                brackets.push(s.charAt(i));
            else
            {
                switch(s.charAt(i))
                {
                    case ')' :
                        if(brackets.peek() == '(')
                            brackets.pop();
                        else
                            brackets.push(s.charAt(i));
                    break;
                    case '}' :
                        if(brackets.peek() == '{')
                            brackets.pop();
                        else
                            brackets.push(s.charAt(i));
                    break;
                    case ']' :
                        if(brackets.peek() == '[')
                            brackets.pop();
                        else
                            brackets.push(s.charAt(i));
                    break;
                    default:
                    brackets.push(s.charAt(i)); 
                }
            }
        }
        
        return brackets.empty();      
    }
}

