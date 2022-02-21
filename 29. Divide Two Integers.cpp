class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long a = (long long)dividend / divisor;
        return min(max(a, (long long)INT_MIN), (long long)INT_MAX);
    }
};
