class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n < 1)
            return false;
        for (; n; n >>= 2)
        {
            if (n == 1)
                return true;
            if (n & 3)
                return false;
        }
        return false;
    }
};
