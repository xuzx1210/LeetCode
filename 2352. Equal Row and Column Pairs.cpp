class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        map<vector<int>, int> counter{};
        for (const vector<int> &row : grid)
            ++counter[row];
        int result = 0;
        for (int j = 0; j < n; ++j)
        {
            vector<int> col(n);
            for (int i = 0; i < n; ++i)
                col[i] = grid[i][j];
            result += counter[col];
        }
        return result;
    }
};
