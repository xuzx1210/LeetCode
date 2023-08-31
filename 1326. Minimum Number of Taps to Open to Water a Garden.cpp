class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
        {
            const int last = min(n, i + ranges[i]), minimum = dp[max(0, i - ranges[i])] + 1;
            for (int j = max(0, i - ranges[i] + 1); j <= last; ++j)
                dp[j] = min(dp[j], minimum);
        }
        if (dp[n] == n + 2)
            return -1;
        return dp[n];
    }
};
