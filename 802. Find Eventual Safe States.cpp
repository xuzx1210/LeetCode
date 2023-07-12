class Solution
{
private:
    vector<bool> visited, safe;
    bool dfs(const int index, const vector<vector<int>> &graph)
    {
        if (visited[index])
            return safe[index];
        visited[index] = true;
        bool result = true;
        for (const int next : graph[index])
            result = result && dfs(next, graph);
        return safe[index] = result;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        visited.resize(n, false);
        safe.resize(n, false);
        vector<int> result{};
        for (int i = 0; i < n; ++i)
            if (dfs(i, graph))
                result.emplace_back(i);
        return result;
    }
};
