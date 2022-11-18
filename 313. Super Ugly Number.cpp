class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        const int size = primes.size();
        vector<size_t> index(size), dp(n, INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < size; ++j)
                dp[i] = min(dp[i], dp[index[j]] * primes[j]);
            for (int j = 0; j < size; ++j)
                if (dp[i] == dp[index[j]] * primes[j])
                    ++index[j];
        }
        return dp.back();
    }
};
