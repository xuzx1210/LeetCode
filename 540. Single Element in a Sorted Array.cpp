class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int middle = (left + right) >> 1;
            if (nums[middle] == nums[middle ^ 1])
                left = middle + 1;
            else
                right = middle;
        }
        return nums[left];
    }
};
