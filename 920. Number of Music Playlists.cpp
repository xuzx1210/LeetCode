class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        const long mod = 1000000007;
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;
        for (int all = 1; all <= goal; ++all)
            for (int used = 1; used <= min(all, n); ++used)
            {
                dp[all][used] = (dp[all - 1][used - 1] * (n - (used - 1))) % mod;
                if (k < used)
                    dp[all][used] = (dp[all][used] + dp[all - 1][used] * (used - k)) % mod;
            }
        return dp[goal][n];
    }
};
