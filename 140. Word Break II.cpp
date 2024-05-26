class Solution
{
private:
    vector<string> result;
    vector<string> path;
    class TrieNode
    {
    private:
        bool stop;
        vector<TrieNode *> next;

    public:
        TrieNode()
        {
            next.resize(26, nullptr);
            stop = false;
        }
        void insert(const int index, const string &word)
        {
            if (index == word.length())
            {
                this->stop = true;
                return;
            }
            const int i = word[index] - 'a';
            if (!next[i])
                next[i] = new TrieNode();
            next[i]->insert(index + 1, word);
        }
        bool isWord()
        {
            return stop;
        }
        bool hasNext(const char c)
        {
            return next[c - 'a'];
        }
        TrieNode *go(const char c)
        {
            return next[c - 'a'];
        }
    };
    class Trie
    {
    public:
        TrieNode *root;
        Trie()
        {
            root = new TrieNode();
        }
        void insert(const string &word)
        {
            root->insert(0, word);
        }
    };
    void dfs(const int index, const string &s, Trie &trie)
    {
        if (index == s.length())
        {
            string tmp(path.front());
            for (int i = 1; i < path.size(); ++i)
                tmp.append(" " + path[i]);
            result.emplace_back(tmp);
            return;
        }
        TrieNode *node = trie.root;
        for (int i = index; i < s.length(); ++i)
        {
            const int c = s[i] - 'a';
            if (!node->hasNext(s[i]))
                break;
            node = node->go(s[i]);
            if (!node->isWord())
                continue;
            path.emplace_back(s, index, i - index + 1);
            dfs(i + 1, s, trie);
            path.pop_back();
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        result.clear();
        path.clear();
        Trie trie;
        for (const string &word : wordDict)
            trie.insert(word);
        dfs(0, s, trie);
        return result;
    }
};
