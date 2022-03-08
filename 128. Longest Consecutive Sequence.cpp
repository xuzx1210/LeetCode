class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 1; --i)
            if (nums[i] == nums[i - 1])
                nums.erase(nums.begin() + i);
        int result = 1;
        int start = 0, end = 1;
        for (; end < nums.size(); ++end)
        {
            if (nums[end] == nums[end - 1] + 1)
                continue;
            result = max(result, end - start);
            start = end;
        }
        return max(result, end - start);
    }
};
