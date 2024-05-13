class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int result = 0;
        const int m = grid.size(), n = grid.front().size();
        for (int i = 0; i < m; ++i)
            if (!grid[i][0])
                for (int j = 0; j < n; ++j)
                    grid[i][j] = !grid[i][j];
        for (int j = 0; j < n; ++j)
        {
            int bitCount = 0;
            for (int i = 0; i < m; ++i)
                bitCount += grid[i][j];
            result = (result << 1) + max(bitCount, m - bitCount);
        }
        return result;
    }
};
