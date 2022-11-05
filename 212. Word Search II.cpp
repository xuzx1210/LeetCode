class TrieNode
{
public:
    vector<TrieNode *> children;
    string word;
    bool isEnd;
    TrieNode()
    {
        children.resize(26);
        word.clear();
        isEnd = false;
    }
    ~TrieNode()
    {
        for (TrieNode *child : children)
            if (child)
                delete child;
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
                int index = c - 'a';
                if (!cur->children[index])
                    cur->children[index] = new TrieNode();
                cur = cur->children[index];
            }
            cur->isEnd = true;
            cur->word = word;
        }
    }
    ~Trie()
    {
        delete root;
    }
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
        if (x < 0 || m <= x || y < 0 || n <= y)
            return;
        char c = board[x][y];
        if (c == ' ')
            return;
        cur = cur->children[c - 'a'];
        if (!cur)
            return;
        if (cur->isEnd)
        {
            result.emplace_back(cur->word);
            cur->isEnd = false;
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
