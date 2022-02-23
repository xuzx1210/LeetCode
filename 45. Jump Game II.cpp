class Solution
{
public:
    int jump(vector<int> &nums)
    {
        const int n = nums.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<pair<int, int>> bfs;
        while (!bfs.empty())
            bfs.pop();
        bfs.push({0, 0});
        while (!bfs.empty())
        {
            int index = bfs.front().first, depth = bfs.front().second;
            if (index == n - 1)
                return depth;
            bfs.pop();
            int maxDistance = nums[index];
            for (int i = max(0, index - maxDistance); i <= min(n - 1, index + maxDistance); ++i)
            {
                if (visited[i])
                    continue;
                bfs.push({i, depth + 1});
                visited[i] = true;
            }
        }
        return 0;
    }
};
