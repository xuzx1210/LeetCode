class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        for (int i = intervals.size() - 1; i > 0; --i)
        {
            int a = intervals[i][0], b = intervals[i][1];
            for (int j = i - 1; j >= 0; --j)
            {
                int c = intervals[j][0], d = intervals[j][1];
                if (a <= c && c <= b || a <= d && d <= b || c <= a && a <= d || c <= b && b <= d)
                {
                    intervals[j][0] = min(a, c);
                    intervals[j][1] = max(b, d);
                    intervals.erase(intervals.begin() + i);
                    break;
                }
            }
        }
        return intervals;
    }
};
