class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (const vector<int> &road : roads)
        {
            const int a = road[0], b = road[1];
            graph[a][b] = graph[b][a] = true;
            ++degree[a];
            ++degree[b];
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                result = max(result, degree[i] + degree[j] - graph[i][j]);
        return result;
    }
};
