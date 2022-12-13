class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        if (n == 1)
            return matrix[0][0];
        for (int i = n - 2; i >= 0; --i)
            for (int j = 0; j < n; ++j)
                if (j == 0)
                    matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j + 1]);
                else if (j == n - 1)
                    matrix[i][j] += min(matrix[i + 1][j - 1], matrix[i + 1][j]);
                else
                    matrix[i][j] += min(matrix[i + 1][j], min(matrix[i + 1][j - 1], matrix[i + 1][j + 1]));
        int result = INT_MAX;
        for (int j = 0; j < n; ++j)
            result = min(result, matrix[0][j]);
        return result;
    }
};
