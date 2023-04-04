class Solution
{
public:
    int partitionString(string s)
    {
        int result = 1, flag = 0;
        for (const char c : s)
        {
            const int offset = c - 'a';
            if (flag & (1 << offset))
            {
                ++result;
                flag = 0;
            }
            flag |= 1 << offset;
        }
        return result;
    }
};
