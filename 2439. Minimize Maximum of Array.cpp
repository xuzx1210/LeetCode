class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        const int n = nums.size();
        int result = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            lldiv_t lld = lldiv(sum, i + 1);
            int average = lld.quot;
            if (lld.rem)
                ++average;
            result = max(result, average);
        }
        return result;
    }
};
