class Solution
{
private:
    class Cell
    {
    public:
        Cell(int a, int b, int c, int d) : x(a), y(b), length(c), remain(d) {}
        int x, y, length, remain;
    };

public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> remain(m, vector<int>(n, -1));
        queue<Cell> bfs;
        bfs.emplace(Cell(0, 0, 0, k));
        while (!bfs.empty())
        {
            Cell cur(bfs.front());
            bfs.pop();
            if (cur.x < 0 || m <= cur.x || cur.y < 0 || n <= cur.y)
                continue;
            if (cur.x == m - 1 && cur.y == n - 1)
                return cur.length;
            if (grid[cur.x][cur.y])
            {
                if (cur.remain)
                    --cur.remain;
                else
                    continue;
            }
            if (remain[cur.x][cur.y] != -1 && remain[cur.x][cur.y] >= cur.remain)
                continue;
            remain[cur.x][cur.y] = cur.remain;
            bfs.emplace(Cell(cur.x - 1, cur.y, cur.length + 1, cur.remain));
            bfs.emplace(Cell(cur.x, cur.y - 1, cur.length + 1, cur.remain));
            bfs.emplace(Cell(cur.x, cur.y + 1, cur.length + 1, cur.remain));
            bfs.emplace(Cell(cur.x + 1, cur.y, cur.length + 1, cur.remain));
        }
        return -1;
    }
};
