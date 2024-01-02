class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        if (n * k < target || target < n)
            return 0;
        const int mod = 1000000007;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int roll = 0; roll < n; ++roll)
            for (int i = min((roll + 1) * k, target); i >= roll; --i)
            {
                dp[i] = 0;
                for (int j = max(0, i - k); j < i; ++j)
                    dp[i] = (dp[i] + dp[j]) % mod;
            }
        return dp[target];
    }
};
