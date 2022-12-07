class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        int sum = 0;
        for (vector<int> &row : grid)
            sum = accumulate(row.begin(), row.end(), sum);
        if (!sum || sum == n * n)
            return new Node(sum, true);
        const int half = n >> 1;
        vector<vector<int>> topLeft{}, topRight{}, bottomLeft{}, bottomRight{};
        for (int i = 0; i < half; ++i)
        {
            topLeft.emplace_back(grid[i].begin(), grid[i].begin() + half);
            topRight.emplace_back(grid[i].begin() + half, grid[i].end());
            bottomLeft.emplace_back(grid[i + half].begin(), grid[i + half].begin() + half);
            bottomRight.emplace_back(grid[i + half].begin() + half, grid[i + half].end());
        }
        return new Node(false, false, construct(topLeft), construct(topRight), construct(bottomLeft), construct(bottomRight));
    }
};
