class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        int water = 0, land = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    ++water;
                else
                    ++land;
        if (water == 0 || land == 0)
            return -1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> bfs{};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                {
                    bfs.push({{i, j}, 0});
                    visited[i][j] = true;
                }
        int result = 0;
        while (!bfs.empty())
        {
            const int x = bfs.front().first.first;
            const int y = bfs.front().first.second;
            const int distance = bfs.front().second;
            bfs.pop();
            result = max(result, distance);
            if (0 < x)
                if (grid[x - 1][y] == 0 && !visited[x - 1][y])
                {
                    bfs.push({{x - 1, y}, distance + 1});
                    visited[x - 1][y] = true;
                }
            if (x < n - 1)
                if (grid[x + 1][y] == 0 && !visited[x + 1][y])
                {
                    bfs.push({{x + 1, y}, distance + 1});
                    visited[x + 1][y] = true;
                }
            if (0 < y)
                if (grid[x][y - 1] == 0 && !visited[x][y - 1])
                {
                    bfs.push({{x, y - 1}, distance + 1});
                    visited[x][y - 1] = true;
                }
            if (y < n - 1)
                if (grid[x][y + 1] == 0 && !visited[x][y + 1])
                {
                    bfs.push({{x, y + 1}, distance + 1});
                    visited[x][y + 1] = true;
                }
        }
        return result;
    }
};
