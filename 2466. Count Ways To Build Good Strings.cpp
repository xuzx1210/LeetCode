class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        const int mod = 1000000007;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int result = 0;
        for (int i = 1; i <= high; ++i)
        {
            if (zero <= i)
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (one <= i)
                dp[i] = (dp[i] + dp[i - one]) % mod;
            if (low <= i)
                result = (result + dp[i]) % mod;
        }
        return result;
    }
};
