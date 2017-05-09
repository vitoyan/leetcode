class Solution {
public:
    void combinationSum(vector<vector<int>>& result, vector<int> &item, int k, int n, int j, int m, int start)
    {
        if(k == j)
        {
            if(n == m)
                result.push_back(item);
            return;
        }
        
        for(int i = start; i < 10; i++)
        {
            int tmp = m + i;
            if(tmp > n)
                break;
            item.push_back(i);
            m = tmp;
            combinationSum(result, item, k, n, j + 1, m, i + 1);
            item.pop_back();
            m = m - i;
        }
            
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if(k <= 0 || n <= 0)
            return result;
        vector<int> item;
        combinationSum(result, item, k, n, 0, 0, 1);
        return result;
    }
};