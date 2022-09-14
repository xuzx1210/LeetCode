class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n < 1)
            return false;
        return !(n & (n - 1)) && !((n - 1) % 3);
    }
};
