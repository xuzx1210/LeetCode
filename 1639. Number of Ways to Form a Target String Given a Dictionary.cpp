class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        const int wordLength = words.front().length(), targetLength = target.length(), MOD = 1000000007;
        vector<long> dp(targetLength + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < wordLength; ++i)
        {
            vector<int> counter(26, 0);
            for (const string &word : words)
                ++counter[word[i] - 'a'];
            for (int j = targetLength - 1; j >= 0; --j)
                dp[j + 1] = (dp[j + 1] + dp[j] * counter[target[j] - 'a']) % MOD;
        }
        return dp[targetLength];
    }
};
