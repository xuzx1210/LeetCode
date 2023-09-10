class Solution
{
public:
    int countOrders(int n)
    {
        const size_t mod = 1000000007;
        size_t result = 1;
        for (size_t i = 1, j = 1; i <= n; ++i, j += 2)
            result = (result * i * j) % mod;
        return result;
    }
};
