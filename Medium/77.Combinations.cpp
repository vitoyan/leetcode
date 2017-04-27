class Solution {
public:

    void combine(vector<vector<int>>& result, vector<int>& item,int n, int k, int start, int m)
    {
        if(m == 0)
        {
            result.push_back(item);
            return;
        }
        for(int i = start; i <= n - m + 1; i++)
        {
            item[k- m] = i;
            combine(result, item, n, k, i + 1, m - 1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k > n)
            return result;
        vector<int> nums(k, 0);
        combine(result, nums, n, k, 1, k);
        return result;
    }
};