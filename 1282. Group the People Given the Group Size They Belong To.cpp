class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> result{};
        const int n = groupSizes.size();
        vector<vector<int>> groups(500, vector<int>{});
        for (int i = 0; i < n; ++i)
        {
            const int size = groupSizes[i];
            groups[size - 1].emplace_back(i);
            if (groups[size - 1].size() == size)
            {
                result.emplace_back(groups[size - 1]);
                groups[size - 1].clear();
            }
        }
        return result;
    }
};
