class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        size_t size = primes.size();
        vector<size_t> ugly(n, INT_MAX), index(size, 0);
        ugly[0] = 1;
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < size; ++j)
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
            for (size_t j = 0; j < size; ++j)
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
        }
        return ugly.back();
    }
};
