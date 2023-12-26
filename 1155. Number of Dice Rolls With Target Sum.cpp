class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        const int mod = 1000000007;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        while (n--)
            for (int i = target; i >= 0; --i)
            {
                dp[i] = 0;
                for (int j = max(0, i - k); j < i; ++j)
                    dp[i] = (dp[i] + dp[j]) % mod;
            }
        return dp[target];
    }
};
