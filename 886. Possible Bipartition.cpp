class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(n, vector<int>{});
        for (vector<int> dislike : dislikes) // create undirected dislike graph
        {
            graph[dislike[0] - 1].emplace_back(dislike[1] - 1);
            graph[dislike[1] - 1].emplace_back(dislike[0] - 1);
        }
        vector<bool> visited(n, false), state(n);
        for (int i = 0; i < n; ++i) // do bfs start with every unvisited person
        {
            if (visited[i])
                continue;
            queue<int> bfs({i});
            visited[i] = true;
            state[i] = false; // no matter false or true here
            for (int size = bfs.size(); size; size = bfs.size())
                while (size--) // all element in queue
                {
                    int cur = bfs.front();
                    bfs.pop();
                    for (int &next : graph[cur]) // all dislike of cur
                        if (!visited[next])
                        {
                            bfs.emplace(next);
                            state[next] = !state[cur];
                            visited[next] = true;
                        }
                        else if (state[next] == state[cur]) // conflict
                            return false;
                }
        }
        return true;
    }
};
