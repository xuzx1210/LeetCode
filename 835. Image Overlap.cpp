class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        vector<vector<int>> matrix(3 * n, vector<int>(3 * n));
        int result = 0;
        for (int si = 0; si < (n << 1); ++si)
            for (int sj = 0; sj < (n << 1); ++sj)
            {
                for (int i = n; i < (n << 1); ++i)
                    for (int j = n; j < (n << 1); ++j)
                        matrix[i][j] = 0;
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        matrix[si + i][sj + j] = img1[i][j];
                int overlap = 0;
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        if (matrix[n + i][n + j] && img2[i][j])
                            ++overlap;
                result = max(result, overlap);
            }
        return result;
    }
};
