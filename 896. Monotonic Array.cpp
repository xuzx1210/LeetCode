class Solution
{
private:
    bool isMonotonicIncreasing(vector<int> &nums)
    {
        for (int i = nums.size() - 1; i; --i)
            if (nums[i - 1] > nums[i])
                return false;
        return true;
    }

public:
    bool isMonotonic(vector<int> &nums)
    {
        if (isMonotonicIncreasing(nums))
            return true;
        reverse(nums.begin(), nums.end());
        if (isMonotonicIncreasing(nums))
            return true;
        return false;
    }
};
