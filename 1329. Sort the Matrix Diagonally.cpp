class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat.front().size();
        unordered_map<int, priority_queue<int>> um = {};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                um[i - j].push(mat[i][j]);
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
            {
                mat[i][j] = um[i - j].top();
                um[i - j].pop();
            }
        return mat;
    }
};
