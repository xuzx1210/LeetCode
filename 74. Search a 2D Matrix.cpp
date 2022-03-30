class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            auto d = div(mid, n);
            int row = d.quot, column = d.rem;
            int num = matrix[row][column];
            if (target > num)
                left = mid + 1;
            else if (target < num)
                right = mid;
            else
                return true;
        }
        return false;
    }
};
