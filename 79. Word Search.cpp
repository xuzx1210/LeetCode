class Solution
{
private:
    vector<vector<char>> board;
    string word;
    int m, n;
    bool dfs(int x, int y, int index)
    {
        if (x < 0 || m <= x || y < 0 || n <= y)
            return false;
        char cur = board[x][y];
        if (cur != word[index++])
            return false;
        if (index == word.length())
            return true;
        board[x][y] = ' ';
        if (dfs(x - 1, y, index))
            return true;
        if (dfs(x, y - 1, index))
            return true;
        if (dfs(x, y + 1, index))
            return true;
        if (dfs(x + 1, y, index))
            return true;
        board[x][y] = cur;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board.front().size();
        this->board = board;
        this->word = word;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(i, j, 0))
                    return true;
        return false;
    }
};
