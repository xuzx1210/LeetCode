class Solution
{
public:
    int fib(int n)
    {
        int tmp = 1, result = 0;
        for (int i = 1; i <= n; ++i)
        {
            tmp += result;
            swap(tmp, result);
        }
        return result;
    }
};
