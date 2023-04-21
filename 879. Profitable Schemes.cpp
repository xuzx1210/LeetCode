class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        const int crimes = group.size(), MOD = 1000000007;
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int crime = 0; crime < crimes; ++crime)
        {
            const int g = group[crime], p = profit[crime];
            for (int i = minProfit; i >= 0; --i)
                for (int j = n - g; j >= 0; --j)
                    dp[min(i + p, minProfit)][j + g] = (dp[min(i + p, minProfit)][j + g] + dp[i][j]) % MOD;
        }
        int result = 0;
        for (int g : dp[minProfit])
            result = (result + g) % MOD;
        return result;
    }
};
