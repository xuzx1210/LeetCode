class Solution
{
private:
    int longestCommonSubstring(string &word1, string &word2)
    {
        int length1 = word1.length(), length2 = word2.length();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 0; i <= length1; ++i)
            dp[i][0] = 0;
        for (int j = 1; j <= length2; ++j)
            dp[0][j] = 0;
        for (int i = 1; i <= length1; ++i)
            for (int j = 1; j <= length2; ++j)
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        return dp.back().back();
    }

public:
    int minDistance(string word1, string word2)
    {
        return word1.length() + word2.length() - (longestCommonSubstring(word1, word2) << 1);
    }
};
