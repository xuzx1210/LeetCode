class Solution
{
public:
    int countOrders(int n)
    {
        vector<unsigned long long> result(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            int options = (i - 1) << 1;
            result[i] = (((options + 1) * (options + 2) >> 1) * result[i - 1]) % 1000000007;
        }
        return result[n];
    }
};
