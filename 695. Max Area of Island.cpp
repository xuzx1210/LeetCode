class Solution
{
private:
    int m, n;
    void next(int x, int y, queue<pair<int, int>> &bfs, vector<vector<int>> &grid)
    {
        if (x < 0 || m <= x || y < 0 || n <= y)
            return;
        if (!grid[x][y])
            return;
        bfs.push({x, y});
        grid[x][y] = 0;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid.front().size();
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    queue<pair<int, int>> bfs({{i, j}});
                    int area = 0;
                    for (; !bfs.empty(); ++area)
                    {
                        pair<int, int> coordinate = bfs.front();
                        bfs.pop();
                        int x = coordinate.first, y = coordinate.second;
                        next(x - 1, y, bfs, grid);
                        next(x + 1, y, bfs, grid);
                        next(x, y - 1, bfs, grid);
                        next(x, y + 1, bfs, grid);
                    }
                    result = max(result, area);
                }
        return result;
    }
};
