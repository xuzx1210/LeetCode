class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int i = 0; i < n; ++i)
            nums[i] |= (nums[i + n] << 10);
        const int mask = (1 << 10) - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            const int index = i << 1;
            nums[index + 1] = nums[i] >> 10;
            nums[index] = nums[i] & mask;
        }
        return nums;
    }
};
// constrain: all nums must less than 512
// time: O(n)
// space: O(1)
