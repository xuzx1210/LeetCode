class Trie
{
private:
    class Node
    {
    private:
        vector<Node *> next;
        bool stopHere;

    public:
        Node()
        {
            next.resize(26, nullptr);
            stopHere = false;
        }
        void insert(string &word, int index)
        {
            if (index == word.length())
            {
                stopHere = true;
                return;
            }
            int c = word[index] - 'a';
            if (!next[c])
            {
                Node *tmp = new Node;
                next[c] = tmp;
            }
            next[c]->insert(word, index + 1);
        }
        bool search(string &word, int index)
        {
            if (index == word.length())
                return stopHere;
            int c = word[index] - 'a';
            if (!next[c])
                return false;
            return next[c]->search(word, index + 1);
        }
        bool startsWith(string &word, int index)
        {
            if (index == word.length())
                return true;
            int c = word[index] - 'a';
            if (!next[c])
                return false;
            return next[c]->startsWith(word, index + 1);
        }
    };
    Node *root;

public:
    Trie()
    {
        Node *tmp = new Node;
        root = tmp;
    }
    void insert(string word)
    {
        root->insert(word, 0);
    }
    bool search(string word)
    {
        return root->search(word, 0);
    }
    bool startsWith(string prefix)
    {
        return root->startsWith(prefix, 0);
    }
};
