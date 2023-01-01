class Solution
{
private:
    int result, m, n;
    vector<vector<bool>> obstacle, visited;
    pair<int, int> end;
    void dfs(int x, int y, int remain)
    {
        if (x < 0 || m <= x || y < 0 || n <= y) // out of boundary
            return;
        if (visited[x][y] || obstacle[x][y]) // visited or obstacle
            return;
        if (x == end.first && y == end.second && !remain) // match
            ++result;
        if (x == end.first && y == end.second || !remain)
            return;
        visited[x][y] = true;
        --remain;
        dfs(x - 1, y, remain);
        dfs(x, y - 1, remain);
        dfs(x, y + 1, remain);
        dfs(x + 1, y, remain);
        visited[x][y] = false;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        result = 0;
        m = grid.size();
        n = grid.front().size();
        obstacle.resize(m, vector<bool>(n, false));
        visited.resize(m, vector<bool>(n, false));
        int remain = 1;
        pair<int, int> start;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    start = {i, j};
                else if (grid[i][j] == 2)
                    end = {i, j};
                else if (grid[i][j] == 0)
                    ++remain;
                else
                    obstacle[i][j] = true;
        dfs(start.first, start.second, remain);
        return result;
    }
};
