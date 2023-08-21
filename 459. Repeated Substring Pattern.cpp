class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        const int length = s.length();
        for (int len = length >> 1; len; --len)
            if (length % len == 0)
            {
                bool repeat = true;
                for (int i = len; i < length; ++i)
                    if (s[i % len] != s[i])
                    {
                        repeat = false;
                        break;
                    }
                if (repeat)
                    return true;
            }
        return false;
    }
};
