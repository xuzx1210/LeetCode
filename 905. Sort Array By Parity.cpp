class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (~nums[right] & 1)
                swap(nums[left++], nums[right]);
            else
                --right;
        }
        return nums;
    }
};
