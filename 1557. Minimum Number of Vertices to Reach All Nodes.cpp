class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<bool> reachable(n, false);
        for (const vector<int> &edge : edges)
            reachable[edge[1]] = true;
        vector<int> result{};
        for (int i = 0; i < n; ++i)
            if (!reachable[i])
                result.emplace_back(i);
        return result;
    }
};
