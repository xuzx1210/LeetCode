class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        const int size = nums.size();
        int result = INT_MAX;
        for (int left = 0, right = 0, sum = 0; right < size; ++right)
        {
            sum += nums[right];
            while (sum - nums[left] >= target)
                sum -= nums[left++];
            if (sum >= target)
                result = min(result, right - left);
        }
        return result == INT_MAX ? 0 : result + 1;
    }
};
