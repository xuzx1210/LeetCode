class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        const long mod = 1000000007;
        vector<long> dp(n + 1, 0);
        dp[1] = n;
        for (int all = 2; all <= goal; ++all)
            for (int used = min(all, n); used; --used)
                dp[used] = (dp[used - 1] * (n - (used - 1)) + dp[used] * (used - k) * (k < used)) % mod;
        return dp[n];
    }
};
