class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        const int n = nums.size();
        int left = 0, right = n;
        while (left < right)
        { // find k
            const int middle = (left + right) >> 1;
            if (nums[0] <= nums[middle])
                left = middle + 1;
            else
                right = middle;
        }
        const int k = n - left;
        left = 0;
        right = n - k;
        while (left < right)
        { // find target in nums[0 : n - k]
            const int middle = (left + right) >> 1;
            const int current = nums[middle];
            if (target < current)
                right = middle;
            else if (current < target)
                left = middle + 1;
            else
                return middle;
        }
        left = n - k;
        right = n;
        while (left < right)
        { // find target in nums[n - k : n]
            const int middle = (left + right) >> 1;
            const int current = nums[middle];
            if (target < current)
                right = middle;
            else if (current < target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};
