class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> inform(n, vector<int>{});
        for (int i = 0; i < n; ++i)
            if (i != headID)
                inform[manager[i]].emplace_back(i);
        int result = 0;
        for (queue<pair<int, int>> bfs({{headID, 0}}); !bfs.empty(); bfs.pop())
        {
            auto [id, time] = bfs.front();
            result = max(result, time);
            time += informTime[id];
            for (int next : inform[id])
                bfs.emplace(next, time);
        }
        return result;
    }
};
