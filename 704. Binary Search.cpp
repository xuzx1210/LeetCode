class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int cur = nums[mid];
            if (cur < target)
                left = mid + 1;
            else if (cur > target)
                right = mid;
            else
                return mid;
        }
        return -1;
    }
};
