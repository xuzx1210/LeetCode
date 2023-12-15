class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        string result{};
        unordered_set<string> sourceCities{};
        for (const vector<string> &path : paths)
            sourceCities.emplace(path[0]);
        for (const vector<string> &path : paths)
            if (sourceCities.find(path[1]) == sourceCities.end())
            {
                result = path[1];
                break;
            }
        return result;
    }
};
