class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        size_t n = grid.size();
        queue<pair<pair<int, int>, int>> bfs = {};
        bfs.push({{0, 0}, 1});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        while (!bfs.empty())
        {
            int i = bfs.front().first.first, j = bfs.front().first.second, depth = bfs.front().second;
            if (i == n - 1 && j == n - 1)
                return depth;
            bfs.pop();
            for (int a = -1; a <= 1; ++a)
            {
                int x = i + a;
                if (x < 0 || n <= x)
                    continue;
                for (int b = -1; b <= 1; ++b)
                {
                    int y = j + b;
                    if (y < 0 || n <= y)
                        continue;
                    if (visited[x][y])
                        continue;
                    if (grid[x][y] == 1)
                        continue;
                    bfs.push({{x, y}, depth + 1});
                    visited[x][y] = true;
                }
            }
        }
        return -1;
    }
};
