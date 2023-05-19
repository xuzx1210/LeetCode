// DFS
class Solution
{
private:
    vector<vector<int>> visited;
    bool error;
    void dfs(const int node, const int currPart, const vector<vector<int>> &graph)
    {
        const int nextPart = !currPart;
        if (visited[node][nextPart])
            error = true;
        if (error || visited[node][currPart])
            return;
        visited[node][currPart] = true;
        for (int i = graph[node].size() - 1; i >= 0 && !error; --i)
            dfs(graph[node][i], nextPart, graph);
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        visited.resize(n, vector<int>(2, false));
        error = false;
        for (int node = 0; node < n && !error; ++node)
            if (!visited[node][0] && !visited[node][1])
                dfs(node, 0, graph);
        return !error;
    }
};

// BFS
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        vector<vector<int>> visited(n, vector<int>(2, false));
        for (int node = 0; node < n; ++node)
        {
            if (visited[node][0] || visited[node][1])
                continue;
            for (queue<pair<int, int>> bfs({{node, 0}}); !bfs.empty(); bfs.pop())
            {
                const int curr = bfs.front().first;
                int part = bfs.front().second;
                if (visited[curr][!part])
                    return false;
                if (visited[curr][part])
                    continue;
                visited[curr][part] = true;
                part = !part;
                for (int next : graph[curr])
                    bfs.emplace(next, part);
            }
        }
        return true;
    }
};
