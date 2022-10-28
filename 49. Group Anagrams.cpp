class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> group;
        for (string &str : strs)
        {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            group[tmp].emplace_back(str);
        }
        vector<vector<string>> result;
        for (auto &[key, value] : group)
            result.emplace_back(value);
        return result;
    }
};
