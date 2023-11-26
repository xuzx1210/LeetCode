class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int result = 0;
        const int m = matrix.size(), n = matrix.front().size();
        for (int j = 0; j < n; ++j)
            for (int i = 1; i < m; ++i)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
        for (vector<int> &row : matrix)
        {
            sort(row.begin(), row.end());
            for (int j = 0; j < n; ++j)
                result = max(result, (n - j) * row[j]);
        }
        return result;
    }
};
