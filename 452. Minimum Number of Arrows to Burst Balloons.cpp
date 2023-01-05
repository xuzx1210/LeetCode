class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        auto compare = [](vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), compare);
        const size_t size = points.size();
        int result = 0, arrow = points[0][1];
        for (size_t i = 1; i < size; ++i)
            if (points[i][0] > arrow)
            {
                ++result;
                arrow = points[i][1];
            }
        return result;
    }
};
