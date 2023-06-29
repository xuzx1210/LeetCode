class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        const int m = grid.size(), n = grid.front().size();
        queue<pair<pair<int, int>, int>> bfs{};
        int k = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                const char curr = grid[i][j];
                if (curr == '@')
                    bfs.emplace(pair<int, int>{i, j}, 0);
                if (islower(curr))
                    k = max(k, curr - 'a');
            }
        ++k;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << k, false)));
        int result = 0;
        while (!bfs.empty())
        {
            int size = bfs.size();
            while (size--)
            {
                const auto [x, y] = bfs.front().first;
                int keys = bfs.front().second;
                bfs.pop();
                if (x < 0 || m <= x || y < 0 || n <= y)
                    continue;
                const char curr = grid[x][y];
                if (curr == '#')
                    continue;
                if (visited[x][y][keys])
                    continue;
                visited[x][y][keys] = true;
                if (isupper(curr) && !(keys & (1 << (curr - 'A'))))
                    continue;
                if (islower(curr))
                {
                    keys |= (1 << (curr - 'a'));
                    visited[x][y][keys] = true;
                }
                if (keys + 1 == (1 << k))
                    return result;
                bfs.emplace(pair<int, int>{x - 1, y}, keys);
                bfs.emplace(pair<int, int>{x, y - 1}, keys);
                bfs.emplace(pair<int, int>{x, y + 1}, keys);
                bfs.emplace(pair<int, int>{x + 1, y}, keys);
            }
            ++result;
        }
        return -1;
    }
};
