class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        for (int left = 0, right = nums.size() - 1; left < right;)
            if (nums[left] & 1 == 1)
                swap(nums[left], nums[right--]);
            else
                ++left;
        return nums;
    }
};
