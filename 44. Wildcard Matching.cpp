class Solution
{
public:
    bool isMatch(string s, string p)
    {
        const size_t sLength = s.length(), pLength = p.length();
        vector<vector<bool>> dp(sLength + 1, vector<bool>(pLength + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= pLength; ++j)
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        for (int i = 1; i <= sLength; ++i)
            for (int j = 1; j <= pLength; ++j)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                dp[i][j] = dp[i][j] || dp[i - 1][j] && p[j - 1] == '*';
                dp[i][j] = dp[i][j] || dp[i][j - 1] && p[j - 1] == '*';
            }
        return dp[sLength][pLength];
    }
};
