class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows, vector<int>({1}));
        for (int i = 1; i < numRows; ++i)
        {
            for (int j = 1; j < i; ++j)
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            result[i].push_back(1);
        }
        return result;
    }
};
