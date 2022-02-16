class Solution
{
public:
    bool palindromic(string &s, int start, int end)
    {
        int length = end - start + 1;
        for (int i = start; i < start + (length >> 1); ++i)
            if (s[i] != s[2 * start + length - i - 1])
                return false;
        return true;
    }
    string longestPalindrome(string s)
    {
        int length = s.length();
        string result;
        result.clear();
        for (int start = 0; start < length; ++start)
        {
            for (int end = start + result.length(); end < length; ++end)
            {
                if (end - start < result.length())
                    continue;
                if (palindromic(s, start, end))
                    result = string(s, start, end - start + 1);
            }
        }
        return result;
    }
};
