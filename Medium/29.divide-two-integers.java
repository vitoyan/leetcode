/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers
 *
 * algorithms
 * Medium (15.96%)
 * Total Accepted:    107.2K
 * Total Submissions: 671.9K
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */

class Solution {
    public long divideHelper(long dividend, long divisor) {
        if(dividend < divisor) return 0;
        
        long sum = divisor;
        long result = 1;
        while((sum + sum) <= dividend) {
            sum = sum + sum;
            result = result + result;
        }
        return result + divideHelper(dividend - sum, divisor);
    }
    public int divide(int dividend, int divisor) {
        if(divisor == 0)
            return Integer.MAX_VALUE;
                
        long lDividend = Math.abs((long)dividend);
        long lDivisor = Math.abs((long)divisor);
        
        if(lDividend == 0 || lDividend < lDivisor)
            return 0;
        int sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;
        long result = divideHelper(lDividend, lDivisor);
        if(result > Integer.MAX_VALUE)
            return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        
        return (int)(sign * result);              
    }
}
