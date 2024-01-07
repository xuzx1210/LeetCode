class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int result = 0;
        const int size = nums.size();
        vector<unordered_map<long, int>> dp(size, unordered_map<long, int>{});
        for (int i = 1; i < size; ++i)
            for (int j = 0; j < i; ++j)
            {
                const long delta = (long)nums[i] - nums[j];
                result += dp[j][delta];
                dp[i][delta] += dp[j][delta] + 1;
            }
        return result;
    }
};
