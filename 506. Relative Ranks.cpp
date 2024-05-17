class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        const int n = score.size();
        vector<string> result(n);
        vector<pair<int, int>> rank(n);
        for (int i = 0; i < n; ++i)
            rank[i] = {score[i], i};
        sort(rank.rbegin(), rank.rend());
        for (int i = 3; i < n; ++i)
            result[rank[i].second] = to_string(i + 1);
        result[rank[0].second] = "Gold Medal";
        if (1 < n)
            result[rank[1].second] = "Silver Medal";
        if (2 < n)
            result[rank[2].second] = "Bronze Medal";
        return result;
    }
};
