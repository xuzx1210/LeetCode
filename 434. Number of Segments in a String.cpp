class Solution
{
public:
    int countSegments(string s)
    {
        int result = 0;
        const size_t length = s.length();
        bool blank = true;
        for (size_t i = 0; i < length; ++i)
            if (s[i] == ' ')
                blank = true;
            else
            {
                if (blank)
                    ++result;
                blank = false;
            }
        return result;
    }
};
