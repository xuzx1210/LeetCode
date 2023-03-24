class Solution
{
private:
    vector<vector<pair<int, bool>>> graph;
    int dfs(int prev, int curr)
    {
        int result = 0;
        for (const auto &[next, connect] : graph[curr])
        {
            if (next == prev)
                continue;
            if (connect)
                ++result;
            result += dfs(curr, next);
        }
        return result;
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        graph.resize(n, vector<pair<int, bool>>{});
        for (const vector<int> &connection : connections)
        {
            graph[connection[0]].emplace_back(connection[1], true);
            graph[connection[1]].emplace_back(connection[0], false);
        }
        return dfs(-1, 0);
    }
};
