class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        const int n = grid.size() - 2;
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int di = 0; di < 3; ++di)
                    for (int dj = 0; dj < 3; ++dj)
                        result[i][j] = max(result[i][j], grid[i + di][j + dj]);
        return result;
    }
};
