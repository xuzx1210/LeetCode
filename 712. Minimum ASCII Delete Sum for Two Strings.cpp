class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        if (s1.length() < s2.length())
            s1.swap(s2);
        const int length1 = s1.length(), length2 = s2.length();
        vector<int> dp(length2 + 1, 0);
        for (int j = 0; j < length2; ++j)
            dp[j + 1] = dp[j] + s2[j];
        for (int i = 0; i < length1; ++i)
        {
            int prev = dp[0];
            dp[0] += s1[i];
            for (int j = 0; j < length2; ++j)
            {
                const int curr = dp[j + 1];
                dp[j + 1] = s1[i] == s2[j] ? prev : min(curr + s1[i], dp[j] + s2[j]);
                prev = curr;
            }
        }
        return dp.back();
    }
};
