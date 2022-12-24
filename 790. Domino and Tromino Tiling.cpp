class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        size_t mod = 1000000007;
        vector<size_t> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
            dp[i] = ((dp[i - 1] << 1) + dp[i - 3]) % mod;
        return dp[n];
    }
};
