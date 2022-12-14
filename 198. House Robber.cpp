class Solution
{
public:
    int rob(vector<int> &nums)
    {
        const size_t size = nums.size();
        if (size == 1)
            return nums[0];
        if (size == 2)
            return max(nums[0], nums[1]);
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]), result;
        for (size_t i = 2; i < size; ++i)
        {
            result = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
};
