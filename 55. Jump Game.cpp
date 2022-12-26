class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        const size_t size = nums.size();
        size_t cur = 0;
        for (size_t maximum = 0; cur < size && cur <= maximum; ++cur)
            maximum = max(maximum, cur + nums[cur]);
        return cur == size;
    }
};
