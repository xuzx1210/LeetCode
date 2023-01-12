class Solution
{
private:
    vector<vector<int>> graph;
    vector<int> result;
    vector<int> dfs(int cur, int pre, string &labels)
    {
        vector<int> total(26, 0);
        for (int &next : graph[cur])
        {
            if (next == pre)
                continue;
            vector<int> tmp(dfs(next, cur, labels));
            for (size_t i = 0; i < 26; ++i)
                total[i] += tmp[i];
        }
        result[cur] = ++total[labels[cur] - 'a'];
        return total;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        graph.resize(n, vector<int>{});
        for (vector<int> &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        result.resize(n, 0);
        dfs(0, -1, labels);
        return result;
    }
};
