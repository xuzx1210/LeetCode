class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            vector<bool> used(9);
            for (int j = 0; j < 9; ++j)
            {
                char cur = board[i][j];
                if (!isdigit(cur))
                    continue;
                if (used[cur - '1'])
                    return false;
                used[cur - '1'] = true;
            }
        }
        for (int j = 0; j < 9; ++j)
        {
            vector<bool> used(9);
            for (int i = 0; i < 9; ++i)
            {
                char cur = board[i][j];
                if (!isdigit(cur))
                    continue;
                if (used[cur - '1'])
                    return false;
                used[cur - '1'] = true;
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                vector<bool> used(9);
                for (int r = 0; r < 3; ++r)
                    for (int c = 0; c < 3; ++c)
                    {
                        char cur = board[i * 3 + r][j * 3 + c];
                        if (!isdigit(cur))
                            continue;
                        if (used[cur - '1'])
                            return false;
                        used[cur - '1'] = true;
                    }
            }
        return true;
    }
};
