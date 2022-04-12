class Solution
{
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m({});
        for (auto num : nums)
            ++m[num];
        vector<pair<int, int>> vp({});
        for (auto a : m)
            vp.push_back(a);
        sort(vp.rbegin(), vp.rend(), compare);
        vector<int> result({});
        for (int i = 0; i < k; ++i)
            result.push_back(vp[i].first);
        return result;
    }
};
