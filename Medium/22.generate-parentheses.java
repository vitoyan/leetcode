/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses
 *
 * algorithms
 * Medium (44.77%)
 * Total Accepted:    157K
 * Total Submissions: 349K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

c class Solution {
    public void generateParenthesis(List<String> result, StringBuilder strPar, int index, int leftBracket, int rightBracket, int pairN) {
        if(index == (pairN*2 - 1)) {
            strPar.append(')');            
            result.add(strPar.toString());
            strPar.deleteCharAt(strPar.length() - 1);
            return;
        }
        
        if(leftBracket < pairN) {
            strPar.append('(');
            generateParenthesis(result, strPar, index + 1, leftBracket + 1, rightBracket, pairN);
            strPar.deleteCharAt(strPar.length() - 1);
        }
        
        if(rightBracket < leftBracket && rightBracket < pairN) {
            strPar.append(')');
            generateParenthesis(result, strPar, index + 1, leftBracket, rightBracket + 1, pairN);
            strPar.deleteCharAt(strPar.length() - 1);
        }
        
        return;
    }
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList();
        if(n <= 0)
            return result;
        int index = 1;
        int leftBracket = 1;
        int rightBracket = 0;
        StringBuilder strPar = new StringBuilder();
        strPar.append('(');
        generateParenthesis(result, strPar, index, leftBracket, rightBracket, n);  
        
        return result;        
    }
}

