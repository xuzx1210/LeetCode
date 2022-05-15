class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>({}));
        for (vector<int> &time : times)
            graph[time[0] - 1].push_back({time[2], time[1] - 1});
        int source = k - 1;
        vector<int> sourceToNodes(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq = {};
        pq.push({0, source});
        sourceToNodes[source] = 0;
        while (!pq.empty())
        {
            int sourceToCur = pq.top().first, cur = pq.top().second;
            pq.pop();
            if (sourceToCur > sourceToNodes[cur])
                continue;
            for (pair<int, int> &edge : graph[cur])
            {
                int curToNext = edge.first, next = edge.second;
                int sourceToNext = sourceToCur + curToNext;
                if (sourceToNext < sourceToNodes[next])
                {
                    sourceToNodes[next] = sourceToNext;
                    pq.push({sourceToNext, next});
                }
            }
        }
        int result = INT_MIN;
        for (int sourceToNode : sourceToNodes)
            result = max(result, sourceToNode);
        return result == INT_MAX ? -1 : result;
    }
};
