class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m - 1; ++i)
        {
            int first = matrix[i][0], limit = min(m - i, n);
            for (int j = 1; j < limit; ++j)
                if (matrix[i + j][j] != first)
                    return false;
        }
        for (int j = 1; j < n - 1; ++j)
        {
            int first = matrix[0][j], limit = min(m, n - j);
            for (int i = 1; i < limit; ++i)
                if (matrix[i][j + i] != first)
                    return false;
        }
        return true;
    }
};
