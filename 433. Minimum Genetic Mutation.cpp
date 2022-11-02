class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_map<string, int> inBank{{start, true}}, visited{{start, true}};
        for (string &str : bank)
            inBank[str] = true;
        queue<pair<string, int>> bfs({{start, 0}});
        while (!bfs.empty())
        {
            string cur(bfs.front().first);
            int depth = bfs.front().second;
            if (cur == end)
                return depth;
            bfs.pop();
            for (int i = 0; i < 8; ++i)
            {
                char tmp = cur[i];
                for (char gene : "ACGT")
                {
                    cur[i] = gene;
                    if (inBank[cur] && !visited[cur])
                    {
                        bfs.emplace(cur, depth + 1);
                        visited[cur] = true;
                    }
                }
                cur[i] = tmp;
            }
        }
        return -1;
    }
};
