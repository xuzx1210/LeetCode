class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> dp(size, 1);
        int result = 1;
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            result = max(result, dp[i]);
        }
        return result;
    }
};
