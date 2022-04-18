class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        int size = m * n;
        k %= size;
        vector<vector<int>> result(grid);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int index = (i * n + j + size - k) % size;
                div_t d = div(index, n);
                result[i][j] = grid[d.quot][d.rem];
            }
        return result;
    }
};
