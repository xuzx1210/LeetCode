class Solution
{
private:
    void emplace(unordered_map<size_t, bool> &visited, queue<pair<size_t, size_t>> &bfs, size_t num, size_t depth)
    {
        if (visited[num])
            return;
        bfs.emplace(num, depth);
        visited[num] = true;
    }

public:
    int integerReplacement(int n)
    {
        unordered_map<size_t, bool> visited{{n, true}};
        queue<pair<size_t, size_t>> bfs({{n, 0}});
        int result;
        while (true)
        {
            size_t cur = bfs.front().first, depth = bfs.front().second;
            if (cur == 1)
            {
                result = depth;
                break;
            }
            bfs.pop();
            ++depth;
            if (cur & 1)
            {
                emplace(visited, bfs, cur - 1, depth);
                emplace(visited, bfs, cur + 1, depth);
            }
            else
                emplace(visited, bfs, cur >> 1, depth);
        }
        return result;
    }
};
