class Solution
{
private:
    int ones(int num)
    {
        int result = 0;
        while (num)
        {
            num &= (num - 1);
            ++result;
        }
        return result;
    }

public:
    int minFlips(int a, int b, int c)
    {
        c ^= a | b;
        return ones(c) + ones(a & b & c);
    }
};
