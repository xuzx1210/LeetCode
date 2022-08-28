class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat.front().size();
        vector<priority_queue<int>> diagonal(m + n - 1);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                diagonal[i - j + n - 1].push(mat[i][j]);
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
            {
                int index = i - j + n - 1;
                mat[i][j] = diagonal[index].top();
                diagonal[index].pop();
            }
        return mat;
    }
};
