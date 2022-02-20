class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        for (int i = 0; i < intervals.size(); ++i)
        {
            bool covered = false;
            for (int j = 0; j < intervals.size(); ++j)
            {
                if (i == j)
                    continue;
                if (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1])
                {
                    covered = true;
                    break;
                }
            }
            if (covered)
            {
                intervals.erase(intervals.begin() + i);
                --i;
            }
        }
        return intervals.size();
    }
};
