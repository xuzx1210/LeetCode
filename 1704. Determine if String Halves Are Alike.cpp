class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        const size_t length = s.length();
        const size_t half = length >> 1;
        size_t a = 0, b = 0;
        for (size_t i = 0; i < length; ++i)
            if (0x208222 >> (s[i] & 0x1f) & 1)
                ++(i < half ? a : b);
        return a == b;
    }
};
