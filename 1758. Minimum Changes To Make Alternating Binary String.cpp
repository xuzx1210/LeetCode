class Solution
{
public:
    int minOperations(string s)
    {
        int changes0 = 0, changes1 = 0;
        bool mode;
        for (const char bit : s)
        {
            if (bit == '0' && mode || bit == '1' && !mode)
                ++changes0;
            if (bit == '1' && mode || bit == '0' && !mode)
                ++changes1;
            mode = !mode;
        }
        return min(changes0, changes1);
    }
};
