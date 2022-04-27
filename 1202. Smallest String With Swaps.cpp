class Solution
{
private:
    int length;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> indexes;
    string tmp, str;
    void init(string &s)
    {
        length = s.length();
        graph.resize(length, {});
        visited.resize(length, false);
        indexes.clear();
        tmp = "";
        str = s;
    }
    void dfs(int cur)
    {
        if (visited[cur])
            return;
        visited[cur] = true;
        indexes.push_back(cur);
        tmp += str[cur];
        for (int next : graph[cur])
            dfs(next);
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        init(s);
        for (const auto &edge : pairs)
        {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 0; i < length; ++i)
        {
            if (visited[i])
                continue;
            indexes.clear();
            tmp = "";
            dfs(i);
            sort(indexes.begin(), indexes.end());
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < indexes.size(); ++j)
                s[indexes[j]] = tmp[j];
        }
        return s;
    }
};
