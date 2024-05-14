class Solution
{
private:
    int m, n;
    int dfs(const int x, const int y, vector<vector<int>> &grid)
    {
        if (x < 0 || m <= x || y < 0 || n <= y || !grid[x][y])
            return 0;
        const int gold = grid[x][y];
        grid[x][y] = 0;
        const int maximum = max({dfs(x - 1, y, grid), dfs(x, y - 1, grid), dfs(x, y + 1, grid), dfs(x + 1, y, grid)});
        grid[x][y] = gold;
        return gold + maximum;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int result = 0;
        m = grid.size();
        n = grid.front().size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result = max(result, dfs(i, j, grid));
        return result;
    }
};
