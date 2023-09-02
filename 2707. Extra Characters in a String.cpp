class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        const int sLength = s.length();
        vector<int> dp(sLength + 1);
        dp[0] = 0;
        for (int i = 1; i <= sLength; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (const string &word : dictionary)
            {
                const int wordLength = word.length();
                if (i < wordLength)
                    continue;
                if (s.substr(i - wordLength, wordLength) == word)
                    dp[i] = min(dp[i], dp[i - wordLength]);
            }
        }
        return dp[sLength];
    }
};
