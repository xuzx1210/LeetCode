class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words = {};
        int start = 0;
        const int sLength = s.length(), length = pattern.length();
        for (int i = 0; i < sLength; ++i)
            if (s[i] == ' ')
            {
                words.emplace_back(s.substr(start, i - start));
                start = i + 1;
            }
        words.emplace_back(s.substr(start, sLength - start));
        if (length != words.size())
            return false;
        unordered_map<char, string> pattern2words = {};
        unordered_map<string, char> words2pattern = {};
        for (int i = 0; i < length; ++i)
        {
            auto p2w = pattern2words.find(pattern[i]);
            auto w2p = words2pattern.find(words[i]);
            if (p2w == pattern2words.end())
            {
                if (w2p == words2pattern.end())
                {
                    pattern2words[pattern[i]] = words[i];
                    words2pattern[words[i]] = pattern[i];
                }
                else
                    return false;
            }
            else if (w2p == words2pattern.end())
                return false;
            else if (pattern2words[pattern[i]] != words[i] || words2pattern[words[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
