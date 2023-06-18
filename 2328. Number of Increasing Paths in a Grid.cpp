class Solution
{
private:
    int m, n, mod;
    vector<vector<int>> dp;
    int dfs(const int previous, const int x, const int y, const vector<vector<int>> &grid)
    {
        if (x < 0 || m <= x || y < 0 || n <= y || grid[x][y] <= previous)
            return 0;
        if (dp[x][y])
            return dp[x][y];
        int result = 1;
        result = (result + dfs(grid[x][y], x - 1, y, grid)) % mod;
        result = (result + dfs(grid[x][y], x, y - 1, grid)) % mod;
        result = (result + dfs(grid[x][y], x, y + 1, grid)) % mod;
        result = (result + dfs(grid[x][y], x + 1, y, grid)) % mod;
        return dp[x][y] = result;
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid.front().size();
        mod = 1000000007;
        dp.resize(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result = (result + dfs(0, i, j, grid)) % mod;
        return result;
    }
};
