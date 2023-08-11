class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            const int middle = (left + right) >> 1;
            if (nums[middle] == target)
                return true;
            if (nums[left] == nums[middle] && nums[middle] == nums[right])
            {
                ++left;
                --right;
            }
            else if (nums[left] <= nums[middle])
            {
                if (nums[left] <= target && target < nums[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else
            {
                if (nums[middle] < target && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return false;
    }
};
