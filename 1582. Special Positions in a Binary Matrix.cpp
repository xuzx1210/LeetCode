class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int result = 0;
        const int m = mat.size(), n = mat.front().size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result += mat[i][j] && row[i] == 1 && col[j] == 1;
        return result;
    }
};
