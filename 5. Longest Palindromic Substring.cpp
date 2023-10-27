class Solution
{
private:
    string result;
    int sLength;
    int maximum;
    void findPalindrome(int left, int right, string &s)
    {
        for (; 0 <= left && right < sLength; --left, ++right)
            if (s[left] != s[right])
                break;
        const int length = right - left - 1;
        if (length <= maximum)
            return;
        maximum = length;
        result = s.substr(left + 1, length);
    }

public:
    string longestPalindrome(string s)
    {
        result.clear();
        sLength = s.length();
        maximum = 0;
        for (int i = 0; i < sLength; ++i)
        {
            findPalindrome(i, i, s);
            findPalindrome(i, i + 1, s);
        }
        return result;
    }
};
