class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, bool> um = {};
        for (int &num : nums)
            um[num] = !um[num];
        vector<int> result = {};
        for (auto &p : um)
            if (p.second)
                result.emplace_back(p.first);
        return result;
    }
};
