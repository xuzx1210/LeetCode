class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>{});
        for (int i = edges.size() - 1; i >= 0; --i)
        {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        priority_queue<pair<double, int>> border{};
        border.emplace(1.0, start);
        vector<bool> expanded(n, false);
        vector<double> probability(n, 0.0);
        probability[start] = 1.0;
        while (!border.empty())
        {
            const double toCur = border.top().first;
            const int cur = border.top().second;
            border.pop();
            if (cur == end)
                return toCur;
            if (expanded[cur])
                continue;
            expanded[cur] = true;
            for (const auto &[next, prob] : graph[cur])
            {
                probability[next] = max(probability[next], toCur * prob);
                border.emplace(probability[next], next);
            }
        }
        return probability[end];
    }
};
