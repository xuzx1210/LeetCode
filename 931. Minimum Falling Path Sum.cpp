class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        for (int i = 1; i < n; ++i)
        {
            matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1]);
            for (int j = 1; j < n - 1; ++j)
                matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
            matrix[i][n - 1] += min(matrix[i - 1][n - 2], matrix[i - 1][n - 1]);
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
