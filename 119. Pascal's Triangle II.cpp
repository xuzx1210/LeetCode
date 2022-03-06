class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result({1});
        for (int i = 0; i < rowIndex; ++i)
        {
            for (int j = result.size() - 1; j >= 1; --j)
                result[j] += result[j - 1];
            result.push_back(1);
        }
        return result;
    }
};
