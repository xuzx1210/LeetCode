class Solution
{
public:
    void push(vector<string> &result, vector<int> &nums, int left, int right)
    {
        if (right == left + 1)
            result.push_back(to_string(nums[left]));
        else
            result.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
    }
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result({});
        if (nums.empty())
            return result;
        if (nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int left = 0, right = 1;
        for (; right < nums.size(); ++right)
        {
            if (nums[right] == nums[right - 1] + 1)
                continue;
            push(result, nums, left, right);
            left = right;
        }
        push(result, nums, left, right);
        return result;
    }
};
