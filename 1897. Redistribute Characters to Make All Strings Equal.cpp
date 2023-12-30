class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        const int size = words.size();
        vector<int> count(26, 0);
        for (const string &word : words)
            for (const char c : word)
                ++count[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (count[i] % size)
                return false;
        return true;
    }
};
