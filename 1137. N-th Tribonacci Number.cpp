class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n < 3)
            return 1;
        int t3 = 0, t2 = 1, t1 = 1, tn;
        for (int i = 3; i <= n; ++i)
        {
            tn = t3 + t2 + t1;
            t3 = t2;
            t2 = t1;
            t1 = tn;
        }
        return tn;
    }
};
