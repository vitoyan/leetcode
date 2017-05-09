class Solution {
public:
    void swap(vector<string>& item, int x, int y)
    {
        string tmp = item[x];
        item[x] = item[y];
        item[y] = tmp;
    }
    bool checkMate(vector<string>& item, int m)
    {
        if(m <= 0)
            return false;
        int index =item[m].find_first_of('Q');
        for(int i = 0; i < m; i++)
        {
            int tmpIndex = item[i].find_first_of('Q');
            if(index == tmpIndex || m - i == index - tmpIndex || m - i == tmpIndex - index)
                return true;
        }
        return false;
        
    }
    void solve(vector<vector<string>>& result, vector<string>& item, int n, int m)
    {
        if(n == m)
        {
            result.push_back(item);
            return;
        }
        for(int i = m; i < n; i++)
        {
            swap(item, m, i);
            if(checkMate(item, m))
            {
                swap(item, m, i);
                continue;
            }
            solve(result, item, n, m + 1);
            swap(item, m, i);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n <= 0)
            return result;
        
        vector<string> item;
        for(int i = 0; i < n; i++)
        {
            string tmp(n, '.');
            tmp[i] = 'Q';
            item.push_back(tmp);
        }
        solve(result, item, n, 0);
        return result;
    }
};