class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        for (queue<tuple<int, int, int>> bfs({{0, 0, 1}}); !bfs.empty(); bfs.pop())
        {
            const auto &[x, y, length] = bfs.front();
            if (x < 0 || n <= x || y < 0 || n <= y || grid[x][y] != 0)
                continue;
            grid[x][y] = 1;
            if (x == n - 1 && y == n - 1)
                return length;
            for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy)
                    bfs.emplace(x + dx, y + dy, length + 1);
        }
        return -1;
    }
};
