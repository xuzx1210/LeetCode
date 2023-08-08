class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        const int size = nums.size();
        int left = 0, right = size;
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            if (nums[0] <= nums[middle])
                left = middle + 1;
            else
                right = middle;
        }
        const int k = size - left;
        left = 0;
        right = size - k;
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            const int num = nums[middle];
            if (target < num)
                right = middle;
            else if (num < target)
                left = middle + 1;
            else
                return middle;
        }
        left = size - k;
        right = size;
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            const int num = nums[middle];
            if (target < num)
                right = middle;
            else if (num < target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};
