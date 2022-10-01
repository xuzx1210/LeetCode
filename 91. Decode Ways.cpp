class Solution
{
public:
    int numDecodings(string s)
    {
        int length = s.length(), one = 1, two;
        for (int i = length - 1; i >= 0; --i)
        {
            int cur = s[i] == '0' ? 0 : one;
            if (i < length - 1)
                if (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')
                    cur += two;
            two = one;
            one = cur;
        }
        return one;
    }
};
