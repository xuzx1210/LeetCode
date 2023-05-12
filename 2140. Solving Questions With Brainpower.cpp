class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        const int size = questions.size();
        vector<long long> dp(size);
        dp[size - 1] = questions[size - 1][0];
        for (int i = size - 2; i >= 0; --i)
        {
            const long long points = questions[i][0], brainpower = questions[i][1];
            dp[i] = points;
            if (i + brainpower + 1 < size)
                dp[i] += dp[i + brainpower + 1];
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};
