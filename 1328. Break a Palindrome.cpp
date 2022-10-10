class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        size_t length = palindrome.length();
        if (length == 1)
            return "";
        size_t half = length >> 1;
        for (size_t i = 0; i < half; ++i)
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        palindrome.back() = 'b';
        return palindrome;
    }
};
