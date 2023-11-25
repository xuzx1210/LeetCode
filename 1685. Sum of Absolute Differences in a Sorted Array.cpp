class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        const int size = nums.size();
        vector<int> result(size, 0);
        for (int i = 1; i < size; ++i)
            result[0] += nums[i] - nums[0];
        for (int i = 1, coefficient = 2 - size; i < size; ++i, coefficient += 2)
            result[i] = result[i - 1] + coefficient * (nums[i] - nums[i - 1]);
        return result;
    }
};
