class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        const size_t m = board.size(), n = board.front().size();
        int result = 0;
        if (board[0][0] == 'X')
            ++result;
        for (size_t i = 1; i < m; ++i)
            if (board[i][0] == 'X' && board[i - 1][0] != 'X')
                ++result;
        for (size_t j = 1; j < n; ++j)
            if (board[0][j] == 'X' && board[0][j - 1] != 'X')
                ++result;
        for (size_t i = 1; i < m; ++i)
            for (size_t j = 1; j < n; ++j)
                if (board[i][j] == 'X' && board[i - 1][j] != 'X' && board[i][j - 1] != 'X')
                    ++result;
        return result;
    }
};
