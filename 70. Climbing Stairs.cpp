class Solution
{
public:
    int climbStairs(int n)
    { // initial index is -1, 0, 1
        int prev2 = 0, prev1 = 1, result = 1;
        for (int i = 2; i <= n; ++i)
        {
            prev2 = prev1;
            prev1 = result;
            result = prev2 + prev1;
        }
        return result;
    }
};
