class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>{});
        for (const vector<int> &road : roads)
        {
            graph[road[0] - 1].emplace_back(road[1] - 1, road[2]);
            graph[road[1] - 1].emplace_back(road[0] - 1, road[2]);
        }
        int result = 10000;
        vector<bool> visited(n, false);
        queue<int> bfs({0});
        while (!bfs.empty())
        {
            const int cur = bfs.front();
            bfs.pop();
            if (visited[cur])
                continue;
            visited[cur] = true;
            for (const auto &[next, distance] : graph[cur])
            {
                result = min(result, distance);
                bfs.emplace(next);
            }
        }
        return result;
    }
};
