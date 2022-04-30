class Solution
{
private:
    int m, n;
    bool check(int i, int j)
    {
        return 0 <= i && i < m && 0 <= j && j < n;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (!check(i, j))
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid.front().size();
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1')
                {
                    ++result;
                    dfs(grid, i, j);
                }
        return result;
    }
};
