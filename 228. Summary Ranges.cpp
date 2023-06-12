class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        const int size = nums.size();
        vector<string> result{};
        for (int begin = 0, end = 1; end <= size; ++end)
        {
            if (end != size && nums[end] - 1 == nums[end - 1])
                continue;
            result.emplace_back(to_string(nums[begin]));
            if (begin < end - 1)
                result.back() += "->" + to_string(nums[end - 1]);
            begin = end;
        }
        return result;
    }
};
