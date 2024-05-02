class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int left = 0, right = nums.size() - 1; left < right;)
            if (nums[left] + nums[right] < 0)
                ++left;
            else if (0 < nums[left] + nums[right])
                --right;
            else
                return nums[right];
        return -1;
    }
};
