class Solution
{
private:
    int m, n;
    vector<vector<int>> heights;
    vector<vector<bool>> pacific, atlantic, visited;
    void dfs(int x, int y, int prevHeight, bool mode)
    {
        if (x < 0 || m <= x || y < 0 || n <= y) // check boundary
            return;
        if (heights[x][y] < prevHeight || visited[x][y] || (mode ? pacific : atlantic)[x][y]) // check condition
            return;
        visited[x][y] = true;
        (mode ? pacific : atlantic)[x][y] = true;
        dfs(x - 1, y, heights[x][y], mode);
        dfs(x, y - 1, heights[x][y], mode);
        dfs(x, y + 1, heights[x][y], mode);
        dfs(x + 1, y, heights[x][y], mode);
        visited[x][y] = false;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        this->heights = heights;
        m = heights.size();
        n = heights.front().size();
        pacific.resize(m, vector<bool>(n, false));
        atlantic.resize(m, vector<bool>(n, false));
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) // from left
            dfs(i, 0, -1, true);
        for (int j = 0; j < n; ++j) // from top
            dfs(0, j, -1, true);
        for (int i = 0; i < m; ++i) // from bottom
            dfs(i, n - 1, -1, false);
        for (int j = 0; j < n; ++j) // from right
            dfs(m - 1, j, -1, false);
        vector<vector<int>> result{};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
        return result;
    }
};
