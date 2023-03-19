class WordDictionary
{
private:
    class TrieNode
    {
    public:
        vector<TrieNode *> alphabet;
        bool isWord;
        TrieNode()
        {
            alphabet.resize(26, nullptr);
            isWord = false;
        }
        void addWord(const string &word, const int index)
        {
            if (word.length() == index)
            {
                isWord = true;
                return;
            }
            TrieNode *&next = alphabet[word[index] - 'a'];
            if (!next)
                next = new TrieNode();
            next->addWord(word, index + 1);
        }
        bool search(const string &word, const int index)
        {
            if (word.length() == index)
                return isWord;
            char c = word[index];
            if (c == '.')
            {
                for (TrieNode *next : alphabet)
                    if (next)
                        if (next->search(word, index + 1))
                            return true;
                return false;
            }
            TrieNode *next = alphabet[c - 'a'];
            return next ? next->search(word, index + 1) : false;
        }
    };
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }
    void addWord(string word)
    {
        root->addWord(word, 0);
    }
    bool search(string word)
    {
        return root->search(word, 0);
    }
};
