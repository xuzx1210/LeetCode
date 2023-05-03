class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<pair<bool, bool>> exist(2001, {false, false});
        for (int num : nums1)
            exist[num + 1000].first = true;
        for (int num : nums2)
            exist[num + 1000].second = true;
        vector<vector<int>> result(2, vector<int>{});
        for (int index = 0; index < 2001; ++index)
            if (exist[index].first && !exist[index].second)
                result[0].emplace_back(index - 1000);
            else if (!exist[index].first && exist[index].second)
                result[1].emplace_back(index - 1000);
        return result;
    }
};
