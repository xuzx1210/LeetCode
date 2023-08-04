class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        const int sLength = s.length();
        vector<bool> dp(sLength + 1, false);
        dp[0] = true;
        for (int i = 0; i < sLength; ++i)
        {
            if (!dp[i])
                continue;
            for (const string &word : wordDict)
            {
                const int wordLength = word.length();
                if (sLength < i + wordLength)
                    continue;
                if (s.substr(i, wordLength) == word)
                    dp[i + wordLength] = true;
            }
        }
        return dp.back();
    }
};
