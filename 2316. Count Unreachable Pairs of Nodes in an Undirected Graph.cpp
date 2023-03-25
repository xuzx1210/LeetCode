class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        // create undirected graph
        vector<vector<int>> graph(n, vector<int>{});
        for (const vector<int> &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        // count size of each group
        vector<int> groupSize{};
        vector<int> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
                continue;
            queue<int> bfs({i});
            groupSize.emplace_back(0);
            while (!bfs.empty())
            {
                const int cur = bfs.front();
                bfs.pop();
                if (visited[cur])
                    continue;
                visited[cur] = true;
                ++groupSize.back();
                for (int next : graph[cur])
                    bfs.emplace(next);
            }
        }
        // calculate result
        long long result = (long long)n * n;
        for (long long size : groupSize)
            result -= size * size;
        result >>= 1;
        return result;
    }
};
