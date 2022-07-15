class Solution
{
private:
    int m, n;
    vector<vector<int>> grid;
    bool inGrid(int x, int y)
    {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    int dfs(int x, int y)
    {
        if (!inGrid(x, y))
            return 0;
        if (!grid[x][y])
            return 0;
        grid[x][y] = 0;
        return dfs(x - 1, y) + dfs(x, y - 1) + dfs(x, y + 1) + dfs(x + 1, y) + 1;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid.front().size();
        this->grid = grid;
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (this->grid[i][j])
                    result = max(result, dfs(i, j));
        return result;
    }
};
