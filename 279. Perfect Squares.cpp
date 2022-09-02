class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int sideLength = 1; sideLength * sideLength <= n; ++sideLength)
        {
            const int square = sideLength * sideLength;
            for (int i = square; i <= n; ++i)
                dp[i] = min(dp[i], dp[i - square] + 1);
        }
        return dp.back();
    }
};
