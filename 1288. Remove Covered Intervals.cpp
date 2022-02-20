class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] < b[0])
            return true;
        if (a[0] > b[0])
            return false;
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        int left = intervals[0][0], right = intervals[0][1];
        int result = 1;
        for (int i = 1; i < intervals.size(); ++i)
        {
            int curLeft = intervals[i][0], curRight = intervals[i][1];
            if (left < curLeft && right < curRight)
                ++result;
            if (right < curRight)
            {
                left = curLeft;
                right = curRight;
            }
        }
        return result;
    }
};
