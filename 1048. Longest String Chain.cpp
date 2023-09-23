class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int result = 1;
        vector<vector<pair<int, int>>> dp(17, vector<pair<int, int>>{});
        for (int i = words.size() - 1; i >= 0; --i)
            dp[words[i].length()].emplace_back(i, 1);
        for (int length = 1; length <= 16; ++length)
            for (auto &[curr, currLen] : dp[length])
            {
                for (auto &[prev, prevLen] : dp[length - 1])
                {
                    int i = 0;
                    for (int j = 0; j < words[curr].length(); ++j)
                        if (words[prev][i] == words[curr][j])
                            ++i;
                    if (i == words[prev].length())
                        currLen = max(currLen, prevLen + 1);
                }
                result = max(result, currLen);
            }
        return result;
    }
};
