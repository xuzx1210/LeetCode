class Solution
{
private:
    vector<vector<int>> stones;
    unordered_map<int, vector<int>> x, y;
    vector<bool> visited;
    void dfs(int index)
    {
        visited[index] = true;
        for (int &next : x[stones[index][0]])
            if (!visited[next])
                dfs(next);
        for (int &next : y[stones[index][1]])
            if (!visited[next])
                dfs(next);
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        this->stones = stones;
        int result = stones.size();
        x.clear();
        y.clear();
        for (int i = 0; i < result; ++i)
        {
            x[stones[i][0]].emplace_back(i);
            y[stones[i][1]].emplace_back(i);
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
