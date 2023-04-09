class Solution
{
private:
    vector<vector<int>> graph;
    bool cycle;
    vector<int> pathVisited, globalVisited;
    vector<vector<int>> dp;
    void maxVector(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < 26; ++i)
            a[i] = max(a[i], b[i]);
    }
    vector<int> dfs(int cur, string &colors)
    {
        if (pathVisited[cur])
        {
            cycle = true;
            return {};
        }
        if (globalVisited[cur])
            return dp[cur];
        globalVisited[cur] = true;
        pathVisited[cur] = true;
        for (int next : graph[cur])
        {
            vector<int> tmp(dfs(next, colors));
            if (cycle)
                return {};
            maxVector(dp[cur], tmp);
        }
        ++dp[cur][colors[cur] - 'a'];
        pathVisited[cur] = false;
        return dp[cur];
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        const int n = colors.size();
        graph.resize(n, vector<int>{});
        for (const vector<int> &edge : edges)
            graph[edge[0]].emplace_back(edge[1]);
        cycle = false;
        pathVisited.resize(n, false);
        globalVisited.resize(n, false);
        dp.resize(n, vector<int>(26, 0));
        vector<int> result(26, 0);
        for (int i = 0; i < n; ++i)
        {
            vector<int> tmp(dfs(i, colors));
            if (cycle)
                return -1;
            maxVector(result, tmp);
        }
        return *max_element(result.begin(), result.end());
    }
};
