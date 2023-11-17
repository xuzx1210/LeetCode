class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        unordered_map<int, vector<int>> stop2routes{};
        for (int routeIndex = 0; routeIndex < routes.size(); ++routeIndex)
            for (const int stop : routes[routeIndex])
                stop2routes[stop].emplace_back(routeIndex);
        unordered_set<int> visited{source};
        queue<pair<int, int>> bfs({{source, 0}});
        while (!bfs.empty())
        {
            auto [curr, bus] = bfs.front();
            bfs.pop();
            if (curr == target)
                return bus;
            ++bus;
            for (const int routeIndex : stop2routes[curr])
            {
                for (const int next : routes[routeIndex])
                    if (visited.find(next) == visited.end())
                    {
                        visited.emplace(next);
                        bfs.emplace(next, bus);
                    }
                routes[routeIndex].clear();
            }
        }
        return -1;
    }
};
