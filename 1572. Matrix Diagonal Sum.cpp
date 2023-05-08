class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        const int n = mat.size(), half = n >> 1;
        int result = 0;
        for (int i = 0; i < n; ++i)
            result += mat[i][i] + mat[i][n - i - 1];
        if (n & 1)
            result -= mat[half][half];
        return result;
    }
};
