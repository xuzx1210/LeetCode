class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        const int sLength = s.length();
        vector<int> dp0(sLength, 0), dp1(sLength, 1);
        // for given length
        // dp0[front]: longest palindrome subsequence length of s[front : front+length-1]
        // dp1[front]: longest palindrome subsequence length of s[front : front+length]
        for (int length = 2; length <= sLength; ++length)
        {
            for (int front = 0, back = length - 1; back < sLength; ++front, ++back)
                dp0[front] = s[front] == s[back] ? dp0[front + 1] + 2 : max(dp1[front], dp1[front + 1]);
            swap(dp0, dp1);
        }
        return dp1[0];
    }
};
