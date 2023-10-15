class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        if (arrLen == 1)
            return 1;
        arrLen = min(arrLen, steps);
        const int mod = 1000000007;
        vector<int> dp(arrLen, 0);
        dp[0] = 1;
        for (int step = 0; step < steps; ++step)
        {
            vector<int> tmp(dp);
            tmp[1] = (tmp[1] + dp[0]) % mod;
            for (int i = 1; i <= arrLen - 2; ++i)
            {
                tmp[i - 1] = (tmp[i - 1] + dp[i]) % mod;
                tmp[i + 1] = (tmp[i + 1] + dp[i]) % mod;
            }
            tmp[arrLen - 2] = (tmp[arrLen - 2] + dp[arrLen - 1]) % mod;
            dp.swap(tmp);
        }
        return dp[0];
    }
};
