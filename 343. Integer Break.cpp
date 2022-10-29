class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        div_t d = div(n, 3);
        if (d.rem == 1)
            return (int)pow(3, d.quot - 1) << 2;
        if (d.rem == 2)
            return (int)pow(3, d.quot) << 1;
        return pow(3, d.quot);
    }
};
