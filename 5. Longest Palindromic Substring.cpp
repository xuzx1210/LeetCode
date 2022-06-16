class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 1)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n + 1));
        for (int i = 0; i < n; ++i)
            dp[i][0] = dp[i][1] = true;
        for (int length = 2; length <= n; ++length)
            for (int start = 0; start <= n - length; ++start)
                dp[start][length] = dp[start + 1][length - 2] && s[start] == s[start + length - 1];
        for (int length = n; length >= 0; --length)
            for (int start = 0; start <= n - length; ++start)
                if (dp[start][length])
                    return s.substr(start, length);
        return s;
    }
};
