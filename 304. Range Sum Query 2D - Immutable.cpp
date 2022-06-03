class NumMatrix
{
private:
    vector<vector<int>> sum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix.front().size();
        sum = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i == 0)
                {
                    if (j == 0)
                        sum[i][j] = matrix[i][j];
                    else
                        sum[i][j] = matrix[i][j] + sum[i][j - 1];
                }
                else
                {
                    if (j == 0)
                        sum[i][j] = matrix[i][j] + sum[i - 1][j];
                    else
                        sum[i][j] = matrix[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                }
    }
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        --row1, --col1;
        if (row1 < 0)
        {
            if (col1 < 0)
                return sum[row2][col2];
            else
                return sum[row2][col2] - sum[row2][col1];
        }
        else
        {
            if (col1 < 0)
                return sum[row2][col2] - sum[row1][col2];
            else
                return sum[row2][col2] - sum[row2][col1] - sum[row1][col2] + sum[row1][col1];
        }
    }
};
