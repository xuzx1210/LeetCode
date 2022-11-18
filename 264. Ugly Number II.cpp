class Solution
{
public:
    int nthUglyNumber(int n)
    {
        const vector<int> factors{2, 3, 5};
        const int size = factors.size();
        vector<int> index(size), dp(n, INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < size; ++j)
                dp[i] = min(dp[i], dp[index[j]] * factors[j]);
            for (int j = 0; j < size; ++j)
                if (dp[i] == dp[index[j]] * factors[j])
                    ++index[j];
        }
        return dp.back();
    }
};
