class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        int mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int dice = 1; dice <= n; ++dice)
            for (int sum = dice; sum <= target && sum <= dice * k; ++sum)
                for (int face = 1; face <= k && face <= sum; ++face)
                    dp[dice][sum] = (dp[dice][sum] + dp[dice - 1][sum - face]) % mod;
        return dp[n][target];
    }
};
