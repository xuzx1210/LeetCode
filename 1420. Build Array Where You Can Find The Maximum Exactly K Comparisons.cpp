class Solution1
{
public:
    int numOfArrays(int n, int m, int k)
    {
        int result = 0;
        const int mod = 1000000007;
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int size = 1; size <= n; ++size)
        {
            for (int cost = k; cost >= 1; --cost)
            {
                int prefix = dp[0][cost - 1];
                for (long maximum = 1; maximum <= m; ++maximum)
                {
                    dp[maximum][cost] = (dp[maximum][cost] * maximum + prefix) % mod;
                    prefix = (prefix + dp[maximum][cost - 1]) % mod;
                }
            }
            dp[0][0] = 0;
        }
        for (int i = 1; i <= m; ++i)
            result = (result + dp[i][k]) % mod;
        return result;
    }
};
