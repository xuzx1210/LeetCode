class Solution
{
public:
    int concatenatedBinary(int n)
    {
        size_t MOD = 1000000007, bits = 0, result = 0;
        for (size_t i = 1; i <= n; ++i)
        {
            if (!(i & (i - 1)))
                ++bits;
            result = ((result << bits) | i) % MOD;
        }
        return result;
    }
};
