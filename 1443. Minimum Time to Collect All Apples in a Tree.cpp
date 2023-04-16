class Solution
{
private:
    vector<vector<int>> graph;
    int result;
    bool dfs(const int previous, const int current, const vector<bool> &hasApple)
    { // whether there exists red node below cur
        bool red = false;
        for (const int next : graph[current])
            if (next != previous && dfs(current, next, hasApple))
            {
                result += 2; // go down and go back
                red = true;
            }
        return red || hasApple[current]; // red node below or current is red node
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        graph.resize(n, vector<int>{});
        for (const vector<int> &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        result = 0;
        dfs(-1, 0, hasApple);
        return result;
    }
};
