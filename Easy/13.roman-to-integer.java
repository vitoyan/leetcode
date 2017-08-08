/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer
 *
 * algorithms
 * Easy (45.57%)
 * Total Accepted:    161.7K
 * Total Submissions: 354.6K
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
public class Solution {
    public int romanToInt(String s) {
	if(s == null || s.length() == 0)
            return 0;
        int result = 0;
        for(int i = s.length() - 1; i >= 0 ; i--)
        {
            switch(s.charAt(i))
            {
                case 'I' :
                    result = result + ( result < 5 ? 1 : -1);
                    break;
                case 'V':
                    result = result + 5;
                    break;
                case 'X':
                    result = result + ( result < 50 ? 10 : -10);
                    break;
                case 'L':
                    result = result + 50;
                    break;
                case 'C':
                    result = result + ( result < 500 ? 100 : -100);
                    break;
                case 'D':
                    result = result + 500;
                    break;
                case 'M':
                    result = result + 1000;
                    break;
                default:
                    break;                
            }
        }
        return result;        
    }
}
