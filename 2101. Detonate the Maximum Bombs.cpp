class Solution
{
private:
    vector<vector<int>> detonate;
    int dfs(const int index, vector<bool> &visited)
    {
        if (visited[index])
            return 0;
        visited[index] = true;
        int result = 1;
        for (const int next : detonate[index])
            result += dfs(next, visited);
        return result;
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        const int n = bombs.size();
        detonate.resize(n, vector<int>{});
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                const int dx = bombs[i][0] - bombs[j][0], dy = bombs[i][1] - bombs[j][1];
                const long long distance = (long long)dx * dx + (long long)dy * dy;
                if (distance <= (long long)bombs[i][2] * bombs[i][2])
                    detonate[i].emplace_back(j);
                if (distance <= (long long)bombs[j][2] * bombs[j][2])
                    detonate[j].emplace_back(i);
            }
        int result = 1;
        for (int i = 0; i < n; ++i)
        {
            vector<bool> visited(n, false);
            result = max(result, dfs(i, visited));
        }
        return result;
    }
};
