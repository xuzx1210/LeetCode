class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int result = 0, mod = 1000000007;
        vector<vector<unsigned int>> paths(m, vector<unsigned int>(n, 0)), boundary(m, vector<unsigned int>(n, 0));
        paths[startRow][startColumn] = 1;
        for (int i = 0; i < m; ++i)
        {
            ++boundary[i][0];
            ++boundary[i][n - 1];
        }
        for (int j = 0; j < n; ++j)
        {
            ++boundary[0][j];
            ++boundary[m - 1][j];
        }
        for (int move = 0; move < maxMove; ++move)
        {
            vector<vector<unsigned int>> tmp(m, vector<unsigned int>(n, 0));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                {
                    int cur = paths[i][j];
                    result = (result + cur * boundary[i][j]) % mod;
                    if (0 < i)
                        tmp[i - 1][j] = (tmp[i - 1][j] + cur) % mod;
                    if (0 < j)
                        tmp[i][j - 1] = (tmp[i][j - 1] + cur) % mod;
                    if (i < m - 1)
                        tmp[i + 1][j] = (tmp[i + 1][j] + cur) % mod;
                    if (j < n - 1)
                        tmp[i][j + 1] = (tmp[i][j + 1] + cur) % mod;
                }
            paths = tmp;
        }
        return result;
    }
};
