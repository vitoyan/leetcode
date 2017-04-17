class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        for(int i = 1; i < m; i++)
        {
            if( n != (int)matrix[i].size())
                return false;
        }
        
        int x = 0;
        int y = n - 1;
        while( x >= 0 && x <= m - 1 && y >= 0 && y <= n-1)
        {
            if(matrix[x][y] == target)
                return true;
            if(target < matrix[x][y])
                y = y - 1;
            else
                x = x + 1;
        }
        
        return false;
    }
};