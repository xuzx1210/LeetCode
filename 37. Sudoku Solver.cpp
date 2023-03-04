class Solution
{
private:
    bool contradiction(vector<vector<char>> &board, const int x, const int y, const char digit)
    {
        const int row = x / 3, col = y / 3;
        for (int i = 0; i < 9; ++i)
            if (board[i][y] == digit || board[x][i] == digit)
                return true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[row * 3 + i][col * 3 + j] == digit)
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>> &board, const int index)
    {
        if (index == 81)
            return true;
        const int x = index / 9, y = index % 9;
        if (board[x][y] != '.')
            return dfs(board, index + 1);
        for (char digit = '1'; digit <= '9'; ++digit)
        {
            if (contradiction(board, x, y, digit))
                continue;
            board[x][y] = digit;
            if (dfs(board, index + 1))
                return true;
        }
        board[x][y] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(board, 0);
    }
};
