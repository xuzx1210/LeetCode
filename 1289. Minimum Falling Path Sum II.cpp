class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        for (int i = 1; i < n; ++i)
        {
            int minimum0 = INT_MAX, minimum1 = INT_MAX;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i - 1][j] < minimum1)
                    minimum1 = grid[i - 1][j];
                if (minimum1 < minimum0)
                    swap(minimum0, minimum1);
            }
            for (int j = 0; j < n; ++j)
                grid[i][j] += grid[i - 1][j] == minimum0 ? minimum1 : minimum0;
        }
        return *min_element(grid.back().begin(), grid.back().end());
    }
};
