class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> result{};
        vector<int> starts{}, ends{};
        for (const vector<int> flower : flowers)
        {
            starts.emplace_back(flower[0]);
            ends.emplace_back(flower[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (const int person : people)
            result.emplace_back((upper_bound(starts.begin(), starts.end(), person) - starts.begin()) - (lower_bound(ends.begin(), ends.end(), person) - ends.begin()));
        return result;
    }
};
