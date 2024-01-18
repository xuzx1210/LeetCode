class Solution
{
public:
    int climbStairs(int n)
    {
        int tmp = 1, result = 1;
        while (--n)
        {
            swap(tmp, result);
            result += tmp;
        }
        return result;
    }
};
