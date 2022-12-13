class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result{};
        for (vector<int> &interval : intervals)
            if (interval[1] < newInterval[0] || newInterval[1] < interval[0])                       // if no overlap:
                result.emplace_back(interval);                                                      // just add interval to result
            else                                                                                    // if overlap:
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])}; // merge interval to newInterval
        for (auto it = result.begin(); it != result.end(); ++it)
            if ((*it)[0] > newInterval[0])
            {
                result.emplace(it, newInterval);
                return result;
            }
        result.emplace_back(newInterval);
        return result;
    }
};
