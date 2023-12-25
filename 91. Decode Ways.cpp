class Solution
{
public:
    int numDecodings(string s)
    {
        int one = s.back() != '0', two = 1;
        for (int i = s.length() - 2; i >= 0; --i)
        {
            int cur = s[i] == '0' ? 0 : one;
            if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
                cur += two;
            two = one;
            one = cur;
        }
        return one;
    }
};
