class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int result = nums[0];
        const int size = nums.size();
        deque<int> maximum{};
        for (int i = 0; i < size; ++i)
        {
            if (!maximum.empty())
                nums[i] += maximum.front();
            result = max(result, nums[i]);
            while (!maximum.empty() && maximum.back() < nums[i])
                maximum.pop_back();
            if (0 < nums[i])
                maximum.emplace_back(nums[i]);
            if (k <= i && !maximum.empty() && maximum.front() == nums[i - k])
                maximum.pop_front();
        }
        return result;
    }
};
