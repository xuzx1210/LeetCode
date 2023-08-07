class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        const int m = matrix.size(), n = matrix.front().size();
        for (int left = 0, right = m * n; left < right;)
        {
            const int middle = (left + right) >> 1;
            const div_t d = div(middle, n);
            const int value = matrix[d.quot][d.rem];
            if (value < target)
                left = middle + 1;
            else if (target < value)
                right = middle;
            else
                return true;
        }
        return false;
    }
};
