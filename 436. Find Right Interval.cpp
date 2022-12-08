class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        const int size = intervals.size();
        map<int, int> location{}; // start, index
        for (int i = 0; i < size; ++i)
            location[intervals[i][0]] = i;
        vector<int> result(size);
        for (int i = 0; i < size; ++i)
        {
            auto it = location.lower_bound(intervals[i][1]);
            result[i] = it == location.end() ? -1 : it->second;
        }
        return result;
    }
};
