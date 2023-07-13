class Solution
{
private:
    vector<bool> visited, path;
    bool dfs(const int index, const vector<vector<int>> &graph)
    {
        if (visited[index])
            return !path[index];
        visited[index] = true;
        path[index] = true;
        for (const int prerequisite : graph[index])
            if (!dfs(prerequisite, graph))
                return false;
        path[index] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>{});
        for (const vector<int> &prerequisite : prerequisites)
            graph[prerequisite[0]].emplace_back(prerequisite[1]);
        visited.resize(numCourses, false);
        path.resize(numCourses, false);
        for (int i = 0; i < numCourses; ++i)
            if (!dfs(i, graph))
                return false;
        return true;
    }
};
