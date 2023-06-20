class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        const int n = nums.size(), size = (k << 1) + 1;
        vector<int> result(n, -1);
        if (n < size)
            return result;
        long long sum = 0;
        for (int i = 0; i < size - 1; ++i)
            sum += nums[i];
        for (int i = k; i + k < n; ++i)
        {
            sum += nums[i + k];
            result[i] = sum / size;
            sum -= nums[i - k];
        }
        return result;
    }
};
