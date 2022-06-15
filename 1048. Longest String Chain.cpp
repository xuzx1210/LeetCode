class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        vector<vector<pair<string, int>>> table(17, vector<pair<string, int>>({}));
        for (string &word : words)
            table[word.length()].push_back({word, 1});
        int result = 1;
        for (int length = 16; length > 0; --length)
            for (auto &cur : table[length])
            {
                result = max(result, cur.second);
                for (int i = 0; i < length; ++i)
                {
                    string substring = cur.first.substr(0, i) + cur.first.substr(i + 1, length - i - 1);
                    for (auto &previous : table[length - 1])
                        if (previous.first == substring)
                            previous.second = max(previous.second, cur.second + 1);
                }
            }
        return result;
    }
};
