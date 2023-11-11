class Graph
{
private:
    int n;
    vector<vector<pair<int, int>>> graph;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        graph.resize(n, {});
        for (const vector<int> &edge : edges)
            graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    void addEdge(vector<int> edge)
    {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    int shortestPath(int node1, int node2)
    {
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
        pq.emplace(0, node1);
        while (!pq.empty())
        {
            const auto [totalCost, curr] = pq.top();
            pq.pop();
            if (visited[curr])
                continue;
            visited[curr] = true;
            if (curr == node2)
                return totalCost;
            for (const auto &[next, cost] : graph[curr])
                pq.emplace(totalCost + cost, next);
        }
        return -1;
    }
};
