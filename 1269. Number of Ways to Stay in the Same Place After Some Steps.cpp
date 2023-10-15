class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        if (arrLen == 1)
            return 1;
        arrLen = min(arrLen, (steps >> 1) + 1);
        const int mod = 1000000007;
        vector<int> dp(arrLen, 0);
        dp[0] = 1;
        for (int step = 0; step < steps; ++step)
        {
            vector<int> tmp(dp);
            dp[1] = (dp[1] + tmp[0]) % mod;
            for (int i = 1; i <= arrLen - 2; ++i)
            {
                dp[i - 1] = (dp[i - 1] + tmp[i]) % mod;
                dp[i + 1] = (dp[i + 1] + tmp[i]) % mod;
            }
            dp[arrLen - 2] = (dp[arrLen - 2] + tmp[arrLen - 1]) % mod;
        }
        return dp[0];
    }
};
