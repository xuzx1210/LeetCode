class Solution
{
public:
    int result;
    vector<vector<bool>> board;
    int rows;
    bool check(const int x, const int y)
    {
        for (int i = 0; i < x; ++i)
            if (board[i][y])
                return false;
        int slash = x + y, backslash = y - x;
        if (slash >= rows)
        {
            for (int i = 1; i < rows - y; ++i)
                if (board[x - i][y + i])
                    return false;
        }
        else
            for (int i = 0; i < x; ++i)
                if (board[i][slash - i])
                    return false;
        if (backslash > 0)
        {
            for (int i = 0; i < x; ++i)
                if (board[i][backslash + i])
                    return false;
        }
        else
            for (int i = 0; i < y; ++i)
                if (board[i - backslash][i])
                    return false;
        return true;
    }
    void dfs(const int cur)
    {
        if (cur == rows)
        {
            ++result;
            return;
        }
        for (int i = 0; i < rows; ++i)
            if (check(cur, i))
            {
                board[cur][i] = true;
                dfs(cur + 1);
                board[cur][i] = false;
            }
    }
    int totalNQueens(int n)
    {
        board = vector<vector<bool>>(n, vector<bool>(n, false));
        result = 0;
        rows = n;
        dfs(0);
        return result;
    }
};
