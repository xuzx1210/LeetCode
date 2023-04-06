class Solution
{
private:
    int m, n;
    void dfs(vector<vector<int>> &grid, const int x, const int y, bool &surrounded)
    {
        if (x < 0 || m <= x || y < 0 || n <= y)
        {
            surrounded = false;
            return;
        }
        if (grid[x][y])
            return;
        grid[x][y] = 1;
        dfs(grid, x - 1, y, surrounded);
        dfs(grid, x, y - 1, surrounded);
        dfs(grid, x, y + 1, surrounded);
        dfs(grid, x + 1, y, surrounded);
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        m = grid.size();
        n = grid.front().size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!grid[i][j])
                {
                    bool surrounded = true;
                    dfs(grid, i, j, surrounded);
                    if (surrounded)
                        ++result;
                }
        return result;
    }
};
