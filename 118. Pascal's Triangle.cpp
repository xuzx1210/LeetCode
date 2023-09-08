class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result{{1}};
        for (int i = 1; i < numRows; ++i)
        {
            result.emplace_back(result.back());
            for (int j = 1; j < i; ++j)
                result[i][j] += result[i - 1][j - 1];
            result[i].emplace_back(1);
        }
        return result;
    }
};
