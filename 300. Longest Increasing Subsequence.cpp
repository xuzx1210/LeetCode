class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int result = 0;
        for (const int num : nums)
            if (result == 0 || nums[result - 1] < num)
                nums[result++] = num;
            else
                *lower_bound(nums.begin(), nums.begin() + result, num) = num;
        return result;
    }
};
