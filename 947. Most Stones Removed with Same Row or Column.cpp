class Solution
{
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    void dfs(int index)
    {
        visited[index] = true;
        for (int &next : graph[index])
            if (!visited[next])
                dfs(next);
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int result = stones.size();
        graph.resize(result);
        for (int i = 0; i < result; ++i)
            for (int j = i + 1; j < result; ++j)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    graph[i].emplace_back(j);
                    graph[j].emplace_back(i);
                }
        visited.resize(result);
        for (int i = result - 1; i >= 0; --i)
            if (!visited[i])
            {
                --result;
                dfs(i);
            }
        return result;
    }
};
