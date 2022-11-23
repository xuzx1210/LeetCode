class Solution
{
public:
    int lastRemaining(int n)
    {
        if (n == 1)
            return 1;
        int half = n >> 1;
        return (half - lastRemaining(half) + 1) << 1;
    }
};
