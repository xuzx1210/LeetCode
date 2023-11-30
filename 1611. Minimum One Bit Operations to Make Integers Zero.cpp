class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int result = 0;
        for (; n; n &= n - 1)
            result = -result - (n ^ (n - 1));
        return result > 0 ? result : -result;
    }
};
