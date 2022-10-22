class Solution
{
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> length;
    int dfs(int index)
    {
        int &result = length[index];
        if (visited[index])
            return result;
        visited[index] = true;
        for (int &next : graph[index])
            result = max(result, dfs(next));
        return ++result;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int size = m * n;
        graph = vector<vector<int>>(size);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int cur = matrix[i][j];
                vector<int> &next = graph[i * n + j];
                if (i)
                    if (cur < matrix[i - 1][j])
                        next.push_back((i - 1) * n + j);
                if (i < m - 1)
                    if (cur < matrix[i + 1][j])
                        next.push_back((i + 1) * n + j);
                if (j)
                    if (cur < matrix[i][j - 1])
                        next.push_back(i * n + j - 1);
                if (j < n - 1)
                    if (cur < matrix[i][j + 1])
                        next.push_back(i * n + j + 1);
            }
        visited = vector<bool>(size, false);
        length = vector<int>(size, 0);
        int result = 0;
        for (int i = 0; i < size; ++i)
            result = max(result, dfs(i));
        return result;
    }
};
