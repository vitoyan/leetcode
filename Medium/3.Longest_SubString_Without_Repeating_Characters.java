Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s == null)
            return 0;
        if(s.length() == 1)
            return 1;
        byte[] bStr = s.getBytes();
        Map<Byte, Integer> mStr = new HashMap<Byte, Integer>();
        int start = 0;
        int max = 0;
        for(int i = 0; i < bStr.length; i++)
        {
            if(!mStr.containsKey(bStr[i]))
            {
                mStr.put(bStr[i], i);
            }
            else
            {
                int tmpLength = i - start;
                max = max > tmpLength ? max : tmpLength;
                int end = mStr.get(bStr[i]);
                for(int j = start; j <= end; j++)
                {
                    mStr.remove(bStr[j]);
                }
                start = end + 1;
                mStr.put(bStr[i], i);
            }
        }
        max = max > mStr.size() ? max : mStr.size();
        return max;
    }
}
