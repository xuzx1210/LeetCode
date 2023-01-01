class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words{};
        stringstream ss(s);
        string word;
        while (ss >> word)
            words.emplace_back(word);
        const size_t length = pattern.length(), size = words.size();
        if (length != size)
            return false;
        unordered_map<char, string> p2w{};
        unordered_map<string, char> w2p{};
        for (size_t i = 0; i < size; ++i)
        {
            auto itp2w = p2w.find(pattern[i]);
            auto itw2p = w2p.find(words[i]);
            bool nop = itp2w == p2w.end(), now = itw2p == w2p.end();
            if (nop && !now || !nop && now) // one exist
                return false;
            if (nop) // no exist
            {
                p2w[pattern[i]] = words[i];
                w2p[words[i]] = pattern[i];
                continue;
            }                                                               // both exist
            if (p2w[pattern[i]] != words[i] || w2p[words[i]] != pattern[i]) // conflict
                return false;
        }
        return true;
    }
};
