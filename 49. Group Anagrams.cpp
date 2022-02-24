class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> um;
        um.clear();
        for (auto str : strs)
        {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            um[tmp].push_back(str);
        }
        vector<vector<string>> result({});
        for (auto it : um)
            result.push_back(it.second);
        return result;
    }
};
