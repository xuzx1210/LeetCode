class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        const int n = adjacentPairs.size() + 1;
        unordered_map<int, set<int>> neighbors;
        for (const vector<int> &adjacentPair : adjacentPairs)
        {
            const int u = adjacentPair[0], v = adjacentPair[1];
            neighbors[u].emplace(v);
            neighbors[v].emplace(u);
        }
        int start;
        for (const auto &[curr, neighbor] : neighbors)
            if (neighbor.size() == 1)
            {
                start = curr;
                break;
            }
        vector<int> result(n);
        for (int prev = INT_MIN, curr = start, i = 0; i < n; ++i)
        {
            result[i] = curr;
            for (const int next : neighbors[curr])
                if (next != prev)
                {
                    prev = curr;
                    curr = next;
                    break;
                }
        }
        return result;
    }
};
