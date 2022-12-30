class Solution
{
private:
    int n;
    vector<vector<int>> graph;
    vector<vector<vector<int>>> pathsFromTarget; // store paths from target to current index: {n-1, ..., cur}
    vector<bool> visited;
    void dfs(const int cur)
    {
        if (visited[cur])
            return;
        visited[cur] = true;
        for (const int &next : graph[cur])
            dfs(next);
        for (const int &next : graph[cur])
            pathsFromTarget[cur].insert(pathsFromTarget[cur].end(), pathsFromTarget[next].begin(), pathsFromTarget[next].end());
        for (vector<int> &path : pathsFromTarget[cur])
            path.emplace_back(cur);
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        this->graph = graph;
        n = graph.size();
        pathsFromTarget.resize(n, vector<vector<int>>{});
        pathsFromTarget[n - 1].push_back({n - 1});
        visited.resize(n, false);
        visited[n - 1] = true;
        dfs(0);
        for (vector<int> &path : pathsFromTarget[0])
            reverse(path.begin(), path.end());
        return pathsFromTarget[0];
    }
};
