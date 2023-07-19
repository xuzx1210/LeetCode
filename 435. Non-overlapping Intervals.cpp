class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int result = 0;
        // find minStartTime and maxEndTime
        int minStartTime = INT_MAX, maxStartTime = INT_MIN;
        for (const vector<int> &interval : intervals)
        {
            minStartTime = min(minStartTime, interval[0]);
            maxStartTime = max(maxStartTime, interval[0]);
        }
        // shift minStartTime to 0
        for (vector<int> &interval : intervals)
        {
            interval[0] -= minStartTime;
            interval[1] -= minStartTime;
        }
        maxStartTime -= minStartTime;
        // index: start time, data: end time
        vector<int> startToEnd(maxStartTime + 1, -1);
        for (const vector<int> &interval : intervals)
        {
            const int start = interval[0], end = interval[1];
            if (startToEnd[start] == -1)
                startToEnd[start] = end;
            else // same start time
            {
                startToEnd[start] = min(startToEnd[start], end); // save the earlier end time
                ++result;
            }
        }
        for (int prev = 0, curr = 1; curr <= maxStartTime; ++curr)
        {
            if (startToEnd[curr] == -1)
                continue;
            if (startToEnd[prev] <= curr)
            {
                prev = curr;
                continue;
            }
            ++result;
            if (startToEnd[curr] < startToEnd[prev])
                prev = curr;
        }
        return result;
    }
};
