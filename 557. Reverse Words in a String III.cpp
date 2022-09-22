class Solution
{
public:
    string reverseWords(string s)
    {
        int length = s.length(), start = 0;
        for (int i = 1; i < length; ++i)
            if (s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        reverse(s.begin() + start, s.begin() + length);
        return s;
    }
};
