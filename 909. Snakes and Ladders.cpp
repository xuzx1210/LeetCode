class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        const int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> column(n);
        iota(column.begin(), column.end(), 0);
        int label = 1;
        for (int row = n - 1; row >= 0; --row)
        {
            for (int col : column)
                cells[label++] = {row, col};
            reverse(column.begin(), column.end());
        }
        vector<int> moves(n * n + 1, -1);
        moves[1] = 0;
        queue<int> bfs({1});
        while (!bfs.empty())
        {
            const int curr = bfs.front();
            bfs.pop();
            for (int next = curr + 1; next <= curr + 6 && next <= n * n; ++next)
            {
                const auto [row, col] = cells[next];
                const int destination = board[row][col] == -1 ? next : board[row][col];
                if (moves[destination] == -1)
                {
                    moves[destination] = moves[curr] + 1;
                    bfs.emplace(destination);
                }
            }
        }
        return moves.back(); // moves[n * n];
    }
};
