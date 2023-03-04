class Solution
{
private:
    bool contradiction(vector<vector<char>> &board, const int x, const int y, vector<bool> &exist)
    {
        const char cur = board[x][y];
        if (cur == '.')
            return false;
        const int index = cur - '1';
        if (exist[index])
            return true;
        exist[index] = true;
        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; ++row)
        {
            vector<bool> exist(9, false);
            for (int col = 0; col < 9; ++col)
                if (contradiction(board, row, col, exist))
                    return false;
        }
        for (int col = 0; col < 9; ++col)
        {
            vector<bool> exist(9, false);
            for (int row = 0; row < 9; ++row)
                if (contradiction(board, row, col, exist))
                    return false;
        }
        for (int ROW = 0; ROW < 3; ++ROW)
            for (int COL = 0; COL < 3; ++COL)
            {
                vector<bool> exist(9, false);
                for (int row = 0; row < 3; ++row)
                    for (int col = 0; col < 3; ++col)
                        if (contradiction(board, ROW * 3 + row, COL * 3 + col, exist))
                            return false;
            }
        return true;
    }
};
