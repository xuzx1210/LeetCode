class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int count = 0;
        for (; left != right; ++count)
        {
            left >>= 1;
            right >>= 1;
        }
        return left << count;
    }
};
