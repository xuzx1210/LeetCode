class Solution
{
private:
    vector<vector<int>> result;
    void recursive(const int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            result.emplace_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i)
        {
            swap(nums[index], nums[i]);
            recursive(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        result.clear();
        recursive(0, nums);
        return result;
    }
};
