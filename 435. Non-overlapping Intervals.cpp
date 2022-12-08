class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int result = 0;
        size_t previous = 0;
        const size_t size = intervals.size();
        for (size_t i = 1; i < size; ++i)
            if (intervals[i][0] < intervals[previous][1])
            {
                ++result;
                if (intervals[i][1] < intervals[previous][1])
                    previous = i;
            }
            else
                previous = i;
        return result;
    }
};
