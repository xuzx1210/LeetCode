class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        const int size = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        int result = INT_MIN, cur = 0;
        for (int i = 1; i < size; ++i)
            cur += i * nums[i];
        for (int i = size - 1; i >= 0; --i)
        {
            cur += sum - nums[i] * size;
            result = max(result, cur);
        }
        return result;
    }
};
