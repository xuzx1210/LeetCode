class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        const long n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0), sum2 = 0;
        for (const int num : nums)
            sum2 += num * num;
        int diff = n * (n + 1) / 2 - sum, diff2 = n * (n + 1) * (2 * n + 1) / 6 - sum2;
        int missing = (diff2 / diff + diff) >> 1;
        return {missing - diff, missing};
    }
};
