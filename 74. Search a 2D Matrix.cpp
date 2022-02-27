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
            int cur = matrix[mid / n][mid % n];
            if (cur < target)
                left = mid + 1;
            else if (cur > target)
                right = mid;
            else
                return true;
        }
        return false;
    }
};
