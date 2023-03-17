class Trie
{
private:
    class TrieNode
    {
    public:
        bool isWord;
        vector<TrieNode *> alphabet;
        TrieNode()
        {
            isWord = false;
            alphabet.resize(26, nullptr);
        }
    };
    TrieNode *root;
    bool find(TrieNode *&node, const string &str)
    {
        const int length = str.length();
        for (int i = 0; i < length; ++i)
        {
            TrieNode *&next = node->alphabet[str[i] - 'a'];
            if (!next)
                return false;
            node = next;
        }
        return true;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *cur = root;
        const int length = word.length();
        for (int i = 0; i < length; ++i)
        {
            TrieNode *&next = cur->alphabet[word[i] - 'a'];
            if (!next)
                next = new TrieNode();
            cur = next;
        }
        cur->isWord = true;
    }
    bool search(string word)
    {
        TrieNode *cur = root;
        if (!find(cur, word))
            return false;
        return cur->isWord;
    }
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        return find(cur, prefix);
    }
};
