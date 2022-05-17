class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int64_t num = n;
        return (num & (num - 1)) == 0 && num;
    }
};
