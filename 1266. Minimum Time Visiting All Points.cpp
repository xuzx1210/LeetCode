class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int result = 0;
        for (int i = points.size() - 1; i; --i)
        {
            int dx = points[i][0] - points[i - 1][0], dy = points[i][1] - points[i - 1][1];
            dx = (dx < 0) * -dx + (0 <= dx) * dx;
            dy = (dy < 0) * -dy + (0 <= dy) * dy;
            result += max(dx, dy);
        }
        return result;
    }
};
