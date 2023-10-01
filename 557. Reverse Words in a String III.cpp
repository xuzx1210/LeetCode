class Solution
{
public:
    string reverseWords(string s)
    {
        s.push_back(' ');
        const int length = s.length();
        for (int begin = 0, end = 0; end < length; ++end)
            if (s[end] == ' ')
            {
                reverse(s.begin() + begin, s.begin() + end);
                begin = end + 1;
            }
        s.pop_back();
        return s;
    }
};
