class Solution
{
public:
    int trailingZeroes(int n)
    {
        int tmp = n / 5;
        return n == 0 ? 0 : tmp + trailingZeroes(tmp);
    }
};
