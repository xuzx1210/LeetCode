class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const size_t length1 = text1.length(), length2 = text2.length();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (size_t i = 1; i <= length1; ++i)
            for (size_t j = 1; j <= length2; ++j)
                dp[i][j] = max(dp[i - 1][j - 1] + (text1[i - 1] == text2[j - 1]), max(dp[i - 1][j], dp[i][j - 1]));
        return dp[length1][length2];
    }
};
