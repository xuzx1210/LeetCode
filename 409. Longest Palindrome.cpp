class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> counter(128);
        for (char c : s)
            ++counter[c];
        int result = 0;
        bool odd = false;
        for (size_t i = 'A'; i <= 'z'; ++i)
        {
            result += counter[i] & -2;
            odd |= counter[i] & 1;
        }
        return odd ? result + 1 : result;
    }
};
