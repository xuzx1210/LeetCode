class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {                              // index 0 for not exist
        vector<size_t> p2i(26, 0); // pattern to index
        map<string, size_t> w2i{}; // word to index
        const size_t length = pattern.length();
        size_t i = 0;
        stringstream ss(s);
        for (string word; ss >> word; ++i)
        {
            if (i >= length) // words is longer than pattern
                return false;
            size_t cur = pattern[i] - 'a';
            if (p2i[cur] != w2i[word]) // not match
                return false;
            p2i[cur] = w2i[word] = i + 1; // update index of char and word
        }
        return i == length; // avoid pattern longer than words
    }
};
