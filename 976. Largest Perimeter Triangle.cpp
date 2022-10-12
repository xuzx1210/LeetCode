class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (size_t i = nums.size() - 1; i >= 2; --i)
        {
            int two = nums[i - 1] + nums[i - 2];
            if (nums[i] < two)
                return nums[i] + two;
        }
        return 0;
    }
};
