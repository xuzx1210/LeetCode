class Solution
{
private:
    int m, n;
    bool surrounded;
    int dfs(vector<vector<int>> &grid, const int x, const int y)
    {
        if (x < 0 || m <= x || y < 0 || n <= y)
        {
            surrounded = false;
            return 0;
        }
        if (!grid[x][y])
            return 0;
        grid[x][y] = 0;
        int result = 1;
        result += dfs(grid, x - 1, y);
        result += dfs(grid, x, y - 1);
        result += dfs(grid, x, y + 1);
        result += dfs(grid, x + 1, y);
        return result;
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int result = 0;
        m = grid.size();
        n = grid.front().size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                surrounded = true;
                int cells = dfs(grid, i, j);
                if (surrounded)
                    result += cells;
            }
        return result;
    }
};
