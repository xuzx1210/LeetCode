class Solution
{
public:
    int m, n;
    int check(int i, int j)
    {
        return 0 <= i && i < m && 0 <= j && j < n;
    }
    int count(vector<vector<int>> &board, int i, int j)
    {
        int result = 0;
        for (int a = -1; a <= 1; ++a)
        {
            int x = i + a;
            for (int b = -1; b <= 1; ++b)
            {
                if (a == 0 && b == 0)
                    continue;
                int y = j + b;
                if (check(x, y))
                    if (board[x][y])
                        ++result;
            }
        }
        return result;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> result(board);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int liveNeighbor = count(board, i, j);
                if (board[i][j])
                    result[i][j] = liveNeighbor == 2 || liveNeighbor == 3;
                else
                    result[i][j] = liveNeighbor == 3;
            }
        board = result;
    }
};
