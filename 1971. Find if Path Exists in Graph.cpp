class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n, vector<int>{});
        for (vector<int> &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        vector<bool> visited(n, false);
        visited[source] = true;
        queue<int> bfs({source});
        while (!bfs.empty())
        {
            int cur = bfs.front();
            if (cur == destination)
                return true;
            bfs.pop();
            for (int &next : graph[cur])
                if (!visited[next])
                {
                    visited[next] = true;
                    bfs.emplace(next);
                }
        }
        return false;
    }
};
