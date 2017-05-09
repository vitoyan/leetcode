class Solution {
public:
     bool checkMate(vector<int>& item, int m)
    {
        if(m <= 0)
            return false;
        int index =item[m];
        for(int i = 0; i < m; i++)
        {
            int tmpIndex = item[i];
            if(index == tmpIndex || m - i == index - tmpIndex || m - i == tmpIndex - index)
                return true;
        }
        return false;
        
    }
    void swap(vector<int>& item, int a, int b)
    {
        int temp = item[a];
        item[a] = item[b];
        item[b] = temp;
    }
    void queens(int& result, vector<int>& item, int n, int m)
    {
        if(checkMate(item, m - 1))
            return;
        if(n == m)
        {
            result++;
            return;
        }
        
        for(int i = m; i < n; i++)
        {
            swap(item, m, i);
            queens(result, item, n, m + 1);
            swap(item, m, i);
        }
        
    }
    int totalNQueens(int n) {
        int result = 0;
        if(n <= 0)
            return result;
        vector<int> item;
        for(int i = 0; i < n; i++)
            item.push_back(i);
        queens(result, item, n, 0);
        return result;
    }
};