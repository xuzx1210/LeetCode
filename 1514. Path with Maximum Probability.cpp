class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>{});
        for (int i = 0; i < edges.size(); ++i)
        {
            const vector<int> &edge = edges[i];
            const int a = edge[0], b = edge[1];
            const double probability = succProb[i];
            graph[a].emplace_back(b, probability);
            graph[b].emplace_back(a, probability);
        }
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> dijkstra{};
        dijkstra.emplace(1.0, start);
        while (!dijkstra.empty())
        {
            const auto [startToCurrProbability, curr] = dijkstra.top();
            dijkstra.pop();
            if (curr == end)
                return startToCurrProbability;
            if (visited[curr])
                continue;
            visited[curr] = true;
            for (const auto &[next, currToNextProbability] : graph[curr])
                dijkstra.emplace(startToCurrProbability * currToNextProbability, next);
        }
        return 0.0;
    }
};
