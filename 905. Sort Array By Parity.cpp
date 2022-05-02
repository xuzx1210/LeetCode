class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] & 1)
            {
                if (nums[right] & 1)
                    --right;
                else
                    swap(nums[left++], nums[right--]);
            }
            else
            {
                if (nums[right] & 1)
                    --right;
                else
                    ++left;
            }
        }
        return nums;
    }
};
