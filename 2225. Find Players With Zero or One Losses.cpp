class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, int> loss;
        for (vector<int> &match : matches)
            loss[match[0]] = loss[match[1]] = 0;
        for (vector<int> &match : matches)
            ++loss[match[1]];
        vector<vector<int>> result(2);
        for (auto &[key, value] : loss)
            if (value < 2)
                result[value].emplace_back(key);
        return result;
    }
};
