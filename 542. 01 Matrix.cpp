class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        const int m = mat.size(), n = mat.front().size();
        queue<pair<int, int>> bfs{};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0)
                    bfs.emplace(i, j);
                else
                    mat[i][j] = -1;
        const vector<int> directions{0, 1, 0, -1, 0};
        while (!bfs.empty())
        {
            const auto [x, y] = bfs.front();
            bfs.pop();
            const int distance = mat[x][y] + 1;
            for (int d = 0; d < 4; ++d)
            {
                const int nextX = x + directions[d], nextY = y + directions[d + 1];
                if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY || mat[nextX][nextY] != -1)
                    continue;
                mat[nextX][nextY] = distance;
                bfs.emplace(nextX, nextY);
            }
        }
        return mat;
    }
};
