class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        const int size = nums.size();
        const int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target == 0)
            return size;
        int maxWindowSize = 0;
        for (int sum = 0, left = 0, right = 0; right < size; ++right)
        {
            sum += nums[right];
            while (target < sum && left < size)
                sum -= nums[left++];
            if (target == sum)
                maxWindowSize = max(maxWindowSize, right - left + 1);
        }
        if (maxWindowSize == 0)
            return -1;
        return size - maxWindowSize;
    }
};
