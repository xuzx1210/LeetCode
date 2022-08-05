class Solution
{
private:
    int dfsAndMemoization(vector<int> &nums, int target, vector<int> &dp)
    {
        if (dp[target] > -1)
            return dp[target];
        dp[target] = 0;
        for (int &num : nums)
            if (num <= target)
                dp[target] += dfsAndMemoization(nums, target - num, dp);
            else
                break;
        return dp[target];
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return dfsAndMemoization(nums, target, dp);
    }
};
