class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid.front().size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                const int diff = (grid[i][j] == 1) - (grid[i][j] != 1);
                row[i] += diff;
                col[j] += diff;
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = row[i] + col[j];
        return grid;
    }
};
