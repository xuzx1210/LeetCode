class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        const int n = cost.size();
        vector<int> dp(n + 1, 500000000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = n; j >= 1; --j)
                dp[j] = min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]);
        return dp[n];
    }
};
