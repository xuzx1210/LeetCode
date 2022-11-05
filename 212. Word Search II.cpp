class TrieNode
{
public:
    vector<TrieNode *> next;
    string word;
    bool isEnd;
    TrieNode()
    {
        next.resize(26);
        word.clear();
        isEnd = false;
    }
    ~TrieNode()
    {
        for (TrieNode *node : next)
            if (node)
                delete node;
    }
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie(vector<string> &words)
    {
        root = new TrieNode();
        for (string &word : words)
        {
            TrieNode *cur = root;
            for (char c : word)
            {
                TrieNode *&tmp = cur->next[c - 'a'];
                if (!tmp)
                    tmp = new TrieNode();
                cur = tmp;
            }
            cur->isEnd = true;
            cur->word = word;
        }
    }
    ~Trie() { delete root; }
    TrieNode *getRoot() { return root; }
};
class Solution
{
private:
    int m, n;
    vector<vector<char>> board;
    vector<string> result;
    void dfs(int x, int y, TrieNode *cur)
    {
        if (x < 0 || m <= x || y < 0 || n <= y) // check boundary
            return;
        char c = board[x][y];
        if (c == ' ') // check visited
            return;
        cur = cur->next[c - 'a'];
        if (!cur) // check existence
            return;
        if (cur->isEnd)
        {
            result.emplace_back(cur->word);
            cur->isEnd = false; // avoid found again
        }
        board[x][y] = ' ';
        dfs(x - 1, y, cur);
        dfs(x, y - 1, cur);
        dfs(x, y + 1, cur);
        dfs(x + 1, y, cur);
        board[x][y] = c;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();
        n = board.front().size();
        this->board = board;
        result.clear();
        Trie trie(words);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(i, j, trie.getRoot());
        return result;
    }
};
