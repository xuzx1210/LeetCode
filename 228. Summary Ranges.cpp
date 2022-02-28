class Solution
{
public:
    void push(vector<string> &result, vector<int> &nums, int size)
    {
        if (size == 1)
            result.push_back(to_string(nums[0]));
        else
            result.push_back(to_string(nums[0]) + "->" + to_string(nums[size - 1]));
        nums.erase(nums.begin(), nums.begin() + size);
    }
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result({});
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1] + 1)
                continue;
            push(result, nums, i);
            i = 0;
        }
        if (!nums.empty())
            push(result, nums, nums.size());
        return result;
    }
};
