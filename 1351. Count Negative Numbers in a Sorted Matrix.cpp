class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid.front().size();
        int result = 0;
        for (int i = m - 1, j = 0; 0 <= i && j < n;)
            if (grid[i][j] < 0)
            {
                result += n - j;
                --i;
            }
            else
                ++j;
        return result;
    }
};
