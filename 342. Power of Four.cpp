class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n < 1)
            return false;
        const int m = n - 1;
        return (n & m) == 0 && m % 3 == 0;
    }
};
