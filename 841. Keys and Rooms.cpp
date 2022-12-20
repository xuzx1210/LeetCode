class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        queue<int> bfs({0});
        while (!bfs.empty())
        {
            int cur = bfs.front();
            bfs.pop();
            for (int &next : rooms[cur])
                if (!visited[next])
                {
                    visited[next] = true;
                    bfs.emplace(next);
                }
        }
        for (bool isVisited : visited)
            if (!isVisited)
                return false;
        return true;
    }
};
