class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minSum(grid);
        for (int i = 1; i < m; ++i)
            minSum[i][0] += minSum[i - 1][0];
        for (int j = 1; j < n; ++j)
            minSum[0][j] += minSum[0][j - 1];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                minSum[i][j] += min(minSum[i - 1][j], minSum[i][j - 1]);
        return minSum.back().back();
    }
};
