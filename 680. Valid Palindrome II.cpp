class Solution
{
public:
    bool check(string &s, int left, int right)
    {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
    bool validPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        while (left < right)
            if (s[left++] != s[right--])
                return check(s, left - 1, right) || check(s, left, right + 1);
        return true;
    }
};
