class Solution
{
public:
    bool done;
    bool check(vector<vector<char>> &board, int x, int y, char target)
    {
        for (int i = 0; i < 9; ++i)
            if (board[x][i] == target)
                return false;
        for (int i = 0; i < 9; ++i)
            if (board[i][y] == target)
                return false;
        int a = (x / 3) * 3, b = (y / 3) * 3;
        for (int i = a; i < a + 3; ++i)
            for (int j = b; j < b + 3; ++j)
                if (board[i][j] == target)
                    return false;
        return true;
    }
    void dfs(vector<vector<char>> &board, const int position)
    {
        if (position == 81)
        {
            done = true;
            return;
        }
        int x = position / 9, y = position % 9;
        if (isdigit(board[x][y]))
            dfs(board, position + 1);
        else
        {
            for (int i = 1; i <= 9; ++i)
            {
                char cur = '0' + i;
                if (check(board, x, y, cur))
                {
                    board[x][y] = cur;
                    dfs(board, position + 1);
                    if (done)
                        return;
                }
            }
            board[x][y] = '.';
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        done = false;
        dfs(board, 0);
    }
};
