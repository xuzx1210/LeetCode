class Solution
{
private:
    int n;
    vector<vector<bool>> visited;
    queue<pair<pair<int, int>, int>> bfs;
    void findBoundary(const int x, const int y, vector<vector<int>> &grid)
    {
        if (x < 0 || n <= x || y < 0 || n <= y || visited[x][y])
            return;
        if (grid[x][y] == 0)
        {
            bfs.push({{x, y}, 0});
            return;
        }
        visited[x][y] = true;
        findBoundary(x - 1, y, grid);
        findBoundary(x, y - 1, grid);
        findBoundary(x, y + 1, grid);
        findBoundary(x + 1, y, grid);
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        n = grid.size();
        visited.resize(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> tmp{};
        bfs.swap(tmp);
        for (int index = 0; index < n * n; ++index)
        {
            const int x = index / n, y = index % n;
            if (grid[x][y] == 1)
            {
                findBoundary(x, y, grid);
                break;
            }
        }
        while (!bfs.empty())
        {
            const int x = bfs.front().first.first, y = bfs.front().first.second, bridge = bfs.front().second;
            bfs.pop();
            if (x < 0 || n <= x || y < 0 || n <= y || visited[x][y])
                continue;
            if (grid[x][y] == 1)
                return bridge;
            visited[x][y] = true;
            bfs.push({{x - 1, y}, bridge + 1});
            bfs.push({{x, y - 1}, bridge + 1});
            bfs.push({{x, y + 1}, bridge + 1});
            bfs.push({{x + 1, y}, bridge + 1});
        }
        return -1;
    }
};
