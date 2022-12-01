class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        const size_t size = nums.size();
        sort(nums.rbegin(), nums.rend());
        int prev = nums.front(), countDown = 2;
        for (size_t i = 1; i < size; ++i)
            if (nums[i] != prev)
            {
                prev = nums[i];
                if (!--countDown)
                    break;
            }
        return countDown ? nums.front() : prev;
    }
};
