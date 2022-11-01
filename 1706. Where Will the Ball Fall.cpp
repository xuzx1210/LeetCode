class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(n);
        iota(result.begin(), result.end(), 0);
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
            {
                if (grid[i][result[j]] == 1)
                {
                    if (result[j] < n - 1)
                        if (grid[i][result[j] + 1] == 1)
                        {
                            ++result[j];
                            continue;
                        }
                }
                else
                {
                    if (result[j])
                        if (grid[i][result[j] - 1] == -1)
                        {
                            --result[j];
                            continue;
                        }
                }
                result[j] = -1;
                break;
            }
        return result;
    }
};
