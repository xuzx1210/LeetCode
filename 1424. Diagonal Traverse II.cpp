class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> result{};
        int diagonalCount = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
            diagonalCount = max(diagonalCount, i + (int)nums[i].size());
        vector<vector<int>> diagonals(diagonalCount, vector<int>{});
        for (int i = nums.size() - 1; i >= 0; --i)
            for (int j = nums[i].size() - 1; j >= 0; --j)
                diagonals[i + j].emplace_back(nums[i][j]);
        for (const vector<int> &diagonal : diagonals)
            result.insert(result.end(), diagonal.begin(), diagonal.end());
        return result;
    }
};
