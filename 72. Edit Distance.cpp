class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        const int length1 = word1.length(), length2 = word2.length();
        vector<int> dp(length2 + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int index1 = 1; index1 <= length1; ++index1) // pre     cur
        {                                                 // dp[i-1] dp[i]
            int pre = dp[0];
            dp[0] = index1;
            for (int index2 = 1; index2 <= length2; ++index2)
            {
                const int cur = dp[index2];
                if (word1[index1 - 1] == word2[index2 - 1])
                    dp[index2] = pre;
                else
                    dp[index2] = min(pre, min(dp[index2 - 1], cur)) + 1;
                pre = cur;
            }
        }
        return dp[length2];
    }
};
