class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        size_t size = nums.size();
        int result = 0;
        vector<unordered_map<int64_t, int>> dp(size);
        for (size_t i = 1; i < size; ++i)
            for (size_t j = 0; j < i; ++j)
            {
                int64_t delta = (int64_t)nums[i] - nums[j];
                int sum = dp[j][delta];
                dp[i][delta] += sum + 1;
                result += sum;
            }
        return result;
    }
};
