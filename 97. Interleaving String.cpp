class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() < s2.length())
            s1.swap(s2);
        const int length1 = s1.length(), length2 = s2.length();
        if (length1 + length2 != s3.length())
            return false;
        vector<bool> dp(length2 + 1, false);
        dp[0] = true;
        for (int j = 1; j <= length2; ++j)
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= length1; ++i)
        {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= length2; ++j)
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1] || dp[j - 1] && s2[j - 1] == s3[i + j - 1];
        }
        return dp[length2];
    }
};
