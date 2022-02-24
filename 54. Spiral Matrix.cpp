class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result({});
        while (!matrix.empty())
        {
            result.insert(result.end(), matrix[0].begin(), matrix[0].end());
            matrix.erase(matrix.begin());
            if (matrix.empty())
                break;
            for (auto it = matrix.begin(); it != matrix.end(); ++it)
            {
                result.push_back(it->back());
                it->pop_back();
            }
            if (matrix[0].empty())
                break;
            result.insert(result.end(), matrix.back().rbegin(), matrix.back().rend());
            matrix.pop_back();
            if (matrix.empty())
                break;
            for (auto it = matrix.rbegin(); it != matrix.rend(); ++it)
            {
                result.push_back((*it)[0]);
                it->erase(it->begin());
            }
            if (matrix[0].empty())
                break;
        }
        return result;
    }
};
