class Solution {
public:
    
    string getPermutation(int n, int k) {
        string result;
        if (k <= 0)
            return result;
        vector<char> nums;
        for (int i = 0; i < n; i++)
            nums.push_back(i + 1 + '0');
        vector<int> facts(n, 1);
        for (int i = 1; i < n; i++)
            facts[i] = facts[i - 1] * i;
        k--;
        while (n)
        {
            int index = k / facts[n - 1];
            result.push_back(nums[index]);
            nums.erase(nums.begin() + index);
            k = k % facts[n - 1];
            n--;
        }
        return result;
    }
};