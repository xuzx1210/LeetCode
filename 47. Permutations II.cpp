class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> answer;
        answer.clear();
        answer.insert(nums);
        while (next_permutation(nums.begin(), nums.end()))
            answer.insert(nums);
        vector<vector<int>> result({});
        for (auto ans : answer)
            result.push_back(ans);
        return result;
    }
};
