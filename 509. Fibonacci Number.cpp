class Solution
{
public:
    int fib(int n)
    {
        if (!n)
            return 0;
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i)
            if (i & 1)
                b += a;
            else
                a += b;
        return n & 1 ? b : a;
    }
};
