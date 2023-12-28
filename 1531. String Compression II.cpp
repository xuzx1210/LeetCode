class Solution
{
private:
    int encodedLength(int length)
    {
        if (100 <= length)
            return 4;
        if (10 <= length)
            return 3;
        if (2 <= length)
            return 2;
        return length;
    }

public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        const int length = s.length();
        vector<vector<int>> dp(length + 1, vector<int>(k + 1, 100));
        dp[0][0] = 0;
        for (int i = 1; i <= length; ++i)
            for (int j = 0; j <= k; ++j)
            {
                if (j)
                    dp[i][j] = dp[i - 1][j - 1];
                for (int p = i, removed = 0, count = 0; p; --p)
                {
                    if (s[p - 1] == s[i - 1])
                        ++count;
                    else if (j < ++removed)
                        break;
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - removed] + encodedLength(count));
                }
            }
        return dp[length][k];
    }
};
