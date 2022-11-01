class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (!n)
            return 1;
        int result = 10;
        for (int i = 2, j = 9, cur = 9; i <= n; ++i, --j)
        {
            cur *= j;
            result += cur;
        }
        return result;
    }
};
