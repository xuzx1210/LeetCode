class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid.front().size();
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                queue<pair<int, int>> bfs({{i, j}});
                int area = 0;
                while (!bfs.empty())
                {
                    pair<int, int> coordinate = bfs.front();
                    bfs.pop();
                    int x = coordinate.first, y = coordinate.second;
                    if (x < 0 || m <= x || y < 0 || n <= y)
                        continue;
                    if (!grid[x][y])
                        continue;
                    ++area;
                    grid[x][y] = 0;
                    bfs.push({x - 1, y});
                    bfs.push({x, y - 1});
                    bfs.push({x, y + 1});
                    bfs.push({x + 1, y});
                }
                result = max(result, area);
            }
        return result;
    }
};
