class Solution
{
public:
    vector<int> numStack;
    vector<vector<int>> result;
    void dfs(int index, int remain, vector<int> &nums)
    {
        if (remain == 0)
        {
            result.push_back(numStack);
            return;
        }
        for (int i = index; i <= nums.size() - remain; ++i)
        {
            numStack.push_back(nums[i]);
            dfs(i + 1, remain - 1, nums);
            numStack.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        numStack.clear();
        result.clear();
        for (int length = 0; length <= nums.size(); ++length)
        {
            dfs(0, length, nums);
        }
        return result;
    }
};
