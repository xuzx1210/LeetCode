class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        const int size = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        for (long sum = 0; right < size; ++right)
        {
            sum += nums[right];
            if (sum + k < (long)nums[right] * (right - left + 1))
                sum -= nums[left++];
        }
        return right - left;
    }
};
