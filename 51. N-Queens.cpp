class Solution
{
public:
    vector<vector<string>> result;
    vector<string> board;
    int rows;
    bool check(const int x, const int y)
    {
        for (int i = 0; i < x; ++i)
            if (board[i][y] == 'Q')
                return false;
        int slash = x + y, backslash = y - x;
        if (slash >= rows)
        {
            for (int i = 1; i < rows - y; ++i)
                if (board[x - i][y + i] == 'Q')
                    return false;
        }
        else
            for (int i = 0; i < x; ++i)
                if (board[i][slash - i] == 'Q')
                    return false;
        if (backslash > 0)
        {
            for (int i = 0; i < x; ++i)
                if (board[i][backslash + i] == 'Q')
                    return false;
        }
        else
            for (int i = 0; i < y; ++i)
                if (board[i - backslash][i] == 'Q')
                    return false;
        return true;
    }
    void dfs(const int cur)
    {
        if (cur == rows)
        {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < rows; ++i)
            if (check(cur, i))
            {
                board[cur][i] = 'Q';
                dfs(cur + 1);
                board[cur][i] = '.';
            }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        board = vector<string>(n, string(n, '.'));
        result.clear();
        rows = n;
        dfs(0);
        return result;
    }
};
