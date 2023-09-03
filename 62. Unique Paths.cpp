class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m < n)
            swap(m, n);
        --m;
        --n;
        long result = 1;
        for (int i = 1; i <= n; ++i)
        {
            result *= (i + m);
            result /= i;
        }
        return result;
    }
};
