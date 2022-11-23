class Solution
{
private:
    unordered_map<int, pair<vector<int>, int>> indices;

public:
    Solution(vector<int> &nums)
    {
        for (int i = nums.size() - 1; i >= 0; --i)
            indices[nums[i]].first.emplace_back(i);
        for (auto &[key, value] : indices)
            value.second = value.first.size();
    }
    int pick(int target)
    {
        return indices[target].first[rand() % indices[target].second];
    }
};
