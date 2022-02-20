class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
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
