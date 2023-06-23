class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        const int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(1001, 0));
        int result = 2;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < i; ++j)
            {
                const int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(dp[j][diff] + 1, 2);
                result = max(result, dp[i][diff]);
            }
        return result;
    }
};
