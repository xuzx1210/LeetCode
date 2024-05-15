class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        // calculate distance with bfs
        queue<pair<int, int>> bfs{};
        // find all thieves
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    bfs.emplace(i, j);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int distance = 0; !bfs.empty(); ++distance)
            for (int size = bfs.size(); size; --size)
            {
                const auto [x, y] = bfs.front();
                bfs.pop();
                if (x < 0 || n <= x || y < 0 || n <= y || visited[x][y])
                    continue;
                visited[x][y] = true;
                grid[x][y] = distance;
                bfs.emplace(x - 1, y);
                bfs.emplace(x, y - 1);
                bfs.emplace(x, y + 1);
                bfs.emplace(x + 1, y);
            }
        // calculate safeness factor with dijkstra
        priority_queue<pair<int, pair<int, int>>> dijkstra{};
        dijkstra.push({grid[0][0], {0, 0}});
        while (!dijkstra.empty())
        {
            const auto [factor, position] = dijkstra.top();
            dijkstra.pop();
            // return 0 if the max safeness factor is 0
            if (!factor)
                break;
            const auto [x, y] = position;
            // continue if the position is expanded
            // reuse visited used by bfs
            if (!visited[x][y])
                continue;
            visited[x][y] = false;
            // get to the end
            if (x == n - 1 && y == n - 1)
                return factor;
            // four direction
            if (x)
                dijkstra.push({min(grid[x - 1][y], factor), {x - 1, y}});
            if (y)
                dijkstra.push({min(grid[x][y - 1], factor), {x, y - 1}});
            if (y < n - 1)
                dijkstra.push({min(grid[x][y + 1], factor), {x, y + 1}});
            if (x < n - 1)
                dijkstra.push({min(grid[x + 1][y], factor), {x + 1, y}});
        }
        return 0;
    }
};
