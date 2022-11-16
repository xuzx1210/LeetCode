class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n, vector<int>(n));
        for (int length = 2; length <= n; ++length)
            for (int start = 0; start + length <= n; ++start)
            {
                int last = start + length - 1, &cur = dp[start][last];
                cur = 1 + min(start + dp[start + 1][last], dp[start][last - 1] + last);
                for (int guess = start + 1; guess < last; ++guess)
                    cur = min(cur, guess + 1 + max(dp[start][guess - 1], dp[guess + 1][last]));
            }
        return dp.front().back();
    }
};
