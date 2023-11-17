class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int result = 0;
        const int n = nums.size(), half = n >> 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < half; ++i)
            result = max(result, nums[i] + nums[n - i - 1]);
        return result;
    }
};
