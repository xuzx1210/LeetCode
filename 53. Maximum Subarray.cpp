class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            result = max(result, nums[i]);
        }
        return result;
    }
};
