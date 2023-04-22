class Solution
{
public:
    int minInsertions(string s)
    {
        const int length = s.length();
        vector<int> dp(length + 1, 0);
        for (int i = 0; i < length; ++i)
        {
            int pre = 0, cur;
            for (int j = 0; j < length; ++j)
            {
                cur = dp[j + 1];
                dp[j + 1] = s[i] == s[length - j - 1] ? pre + 1 : max(dp[j], cur);
                pre = cur;
            }
        }
        return length - dp[length];
    }
};
