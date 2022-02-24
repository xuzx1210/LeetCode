
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1, nums);
        while (next_permutation(nums.begin(), nums.end()))
            result.push_back(nums);
        return result;
    }
};
