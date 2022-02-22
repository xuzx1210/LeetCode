class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            vector<bool> record(9, false);
            for (int j = 0; j < 9; ++j)
            {
                char cur = board[i][j];
                if (isdigit(cur))
                {
                    if (record[cur - '1'])
                        return false;
                    else
                        record[cur - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            vector<bool> record(9, false);
            for (int j = 0; j < 9; ++j)
            {
                char cur = board[j][i];
                if (isdigit(cur))
                {
                    if (record[cur - '1'])
                        return false;
                    else
                        record[cur - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                vector<bool> record(9, false);
                for (int k = 0; k < 3; ++k)
                    for (int l = 0; l < 3; ++l)
                    {
                        char cur = board[i * 3 + k][j * 3 + l];
                        if (isdigit(cur))
                        {
                            if (record[cur - '1'])
                                return false;
                            else
                                record[cur - '1'] = true;
                        }
                    }
            }
        return true;
    }
};
