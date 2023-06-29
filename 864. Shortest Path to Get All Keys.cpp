class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        const int m = grid.size(), n = grid.front().size(); // size of grid
        queue<pair<pair<int, int>, int>> bfs{};
        int k = 0; // number of keys
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                const char curr = grid[i][j];
                if (curr == '@') // is start position
                    bfs.emplace(pair<int, int>{i, j}, 0);
                if (islower(curr)) // is key
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
                if (x < 0 || m <= x || y < 0 || n <= y) // out of range
                    continue;
                const char curr = grid[x][y];
                if (curr == '#') // is wall
                    continue;
                if (visited[x][y][keys]) // is visited
                    continue;
                visited[x][y][keys] = true;
                if (isupper(curr) && !(keys & (1 << (curr - 'A')))) // cannot unlock
                    continue;
                if (islower(curr)) // is key
                {
                    keys |= (1 << (curr - 'a'));
                    visited[x][y][keys] = true;
                }
                if (keys + 1 == (1 << k)) // get all keys
                    return result;
                bfs.emplace(pair<int, int>{x - 1, y}, keys); // push
                bfs.emplace(pair<int, int>{x, y - 1}, keys); // four
                bfs.emplace(pair<int, int>{x, y + 1}, keys); // direction
                bfs.emplace(pair<int, int>{x + 1, y}, keys); // back
            }
            ++result;
        }
        return -1;
    }
};
