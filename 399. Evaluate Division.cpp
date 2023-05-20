class Solution
{
private:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_map<string, bool> visited;
    string target;
    double dfs(const string &current)
    {
        if (current == target)
            return 1.0;
        if (visited[current] || graph.find(current) == graph.end())
            return -1.0;
        visited[current] = true;
        for (const auto &[next, value] : graph[current])
        {
            double result = dfs(next);
            if (result != -1.0)
                return value * result;
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        const int size = equations.size();
        graph.clear();
        for (int i = 0; i < size; ++i)
        {
            const string &vertex0 = equations[i][0];
            const string &vertex1 = equations[i][1];
            const double value = values[i];
            graph[vertex0].emplace_back(vertex1, value);
            graph[vertex1].emplace_back(vertex0, 1.0 / value);
        }
        vector<double> result{};
        for (const vector<string> query : queries)
        {
            target = query[1];
            if (graph.find(target) == graph.end())
            {
                result.emplace_back(-1.0);
                continue;
            }
            visited.clear();
            result.emplace_back(dfs(query[0]));
        }
        return result;
    }
};
