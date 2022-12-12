class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<pair<char, bool>> pattern{}; // first: char (include '.'), second: repeat star
        for (char c : p)
            if (c == '*')
                pattern.back().second = true;
            else
                pattern.emplace_back(c, false);
        const size_t length = s.length(), size = pattern.size();
        vector<vector<bool>> dp(length + 1, vector<bool>(size + 1, false)); // i, j: whether s[0:i] and pattern[0:j] match
        dp[0][0] = true;
        for (int j = 1; j <= size; ++j)
            dp[0][j] = dp[0][j - 1] && pattern[j - 1].second;
        for (int i = 1; i <= length; ++i)
            for (int j = 1; j <= size; ++j)
            {
                bool match = s[i - 1] == pattern[j - 1].first || pattern[j - 1].first == '.';
                dp[i][j] = dp[i][j] || dp[i - 1][j - 1] && match;
                dp[i][j] = dp[i][j] || dp[i][j - 1] && pattern[j - 1].second;
                dp[i][j] = dp[i][j] || dp[i - 1][j] && pattern[j - 1].second && match;
            }
        return dp[length][size];
    }
};
