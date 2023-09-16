class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int result;
        const int rows = heights.size(), columns = heights.front().size();
        vector<vector<int>> minimumEffort(rows, vector<int>(columns, INT_MAX));
        vector<int> direction{0, 1, 0, -1, 0};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq{};
        pq.push({0, {0, 0}});
        minimumEffort[0][0] = 0;
        while (!pq.empty())
        {
            const int effort = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            if (x == rows - 1 && y == columns - 1)
            {
                result = effort;
                break;
            }
            for (int i = 0; i < 4; ++i)
            {
                const int nextX = x + direction[i], nextY = y + direction[i + 1];
                if (nextX < 0 || rows <= nextX || nextY < 0 || columns <= nextY)
                    continue;
                const int currentEffort = max(effort, abs(heights[x][y] - heights[nextX][nextY]));
                if (minimumEffort[nextX][nextY] <= currentEffort)
                    continue;
                minimumEffort[nextX][nextY] = currentEffort;
                pq.push({minimumEffort[nextX][nextY], {nextX, nextY}});
            }
        }
        return result;
    }
};
