class Solution
{
public:
    int n;
    void fourElementRotate(vector<vector<int>> &matrix, int x, int y)
    {
        int a = n - x - 1, b = n - y - 1, tmp = matrix[x][y];
        matrix[x][y] = matrix[b][x];
        matrix[b][x] = matrix[a][b];
        matrix[a][b] = matrix[y][a];
        matrix[y][a] = tmp;
    }
    void rotate(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        int half = n >> 1;
        for (int i = 0; i < half; ++i)
            for (int j = 0; j < half; ++j)
                fourElementRotate(matrix, i, j);
        if (n & 1)
            for (int i = 0; i < half; ++i)
                fourElementRotate(matrix, i, half);
    }
};
