class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        return dp.back();
    }
};
