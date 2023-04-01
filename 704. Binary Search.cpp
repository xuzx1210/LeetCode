class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        for (int left = 0, right = nums.size(); left < right;)
        {
            const int middle = (left + right) >> 1;
            const int cur = nums[middle];
            if (target < cur)
                right = middle;
            else if (cur < target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};
