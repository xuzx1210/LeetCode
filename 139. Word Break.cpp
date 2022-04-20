class Solution
{
public:
    bool equal(string &s, int index, string &word)
    {
        if (index + word.length() > s.length())
            return false;
        for (int i = 0; i < word.length(); ++i)
            if (s[index + i] != word[i])
                return false;
        return true;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int length = s.length();
        vector<bool> dp(length + 1, false);
        dp[0] = true;
        for (int i = 0; i < length; ++i)
        {
            if (!dp[i])
                continue;
            for (string &word : wordDict)
            {
                if (dp[i + word.length()])
                    continue;
                if (equal(s, i, word))
                    dp[i + word.length()] = true;
            }
        }
        return dp[length];
    }
};
