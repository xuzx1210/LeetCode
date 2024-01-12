class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        const int length = s.length(), half = length >> 1;
        int a = 0, b = 0;
        for (int i = 0; i < half; ++i)
            if (0x208222 >> (s[i] & 0x1f) & 1)
                ++a;
        for (int i = half; i < length; ++i)
            if (0x208222 >> (s[i] & 0x1f) & 1)
                ++b;
        return a == b;
    }
};
