class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int result = 0;
        auto cmp = [](const vector<int> &a, const vector<int> &b)
        {
            return a[0] < b[0];
        };
        sort(points.begin(), points.end(), cmp);
        for (int i = points.size() - 1; i; --i)
            result = max(result, points[i][0] - points[i - 1][0]);
        return result;
    }
};
