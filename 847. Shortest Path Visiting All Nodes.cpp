class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int result = 0;
        const int n = graph.size();
        const int all = (1 << n) - 1;
        queue<pair<int, int>> bfs{};
        for (int i = 0; i < n; ++i)
            bfs.emplace(i, 1 << i);
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        while (!bfs.empty())
        {
            bool done = false;
            for (int index = bfs.size(); index; --index)
            {
                const int node = bfs.front().first, mask = bfs.front().second;
                bfs.pop();
                if (mask == all)
                {
                    done = true;
                    break;
                }
                if (visited[node][mask])
                    continue;
                visited[node][mask] = true;
                for (const int next : graph[node])
                    bfs.emplace(next, mask | (1 << next));
            }
            if (done)
                break;
            ++result;
        }
        return result;
    }
};
