class Solution
{
private:
    vector<vector<int>> result;
    vector<int> subset;
    void dfs(int index, vector<int> &nums)
    {
        if (index == 0)
        {
            result.emplace_back(subset);
            return;
        }
        --index;
        dfs(index, nums);
        subset.emplace_back(nums[index]);
        dfs(index, nums);
        subset.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.clear();
        subset.clear();
        dfs(nums.size(), nums);
        return result;
    }
};
