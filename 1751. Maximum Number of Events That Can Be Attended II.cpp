class Solution
{
private:
    vector<vector<int>> dp;
    int solve(const int index, const int remain, const int lastDay, const vector<vector<int>> &events)
    {
        if (index == events.size() || remain == 0)
            return 0;
        const vector<int> &event = events[index];
        const int startDay = event[0], endDay = event[1], value = event[2];
        const int noAttend = solve(index + 1, remain, lastDay, events);
        if (startDay <= lastDay)
            return noAttend;
        if (dp[index][remain] != -1)
            return dp[index][remain];
        const int attend = value + solve(index + 1, remain - 1, endDay, events);
        return dp[index][remain] = max(attend, noAttend);
    }

public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        const int size = events.size();
        sort(events.begin(), events.end());
        dp.resize(size, vector<int>(k + 1, -1));
        return solve(0, k, 0, events);
    }
};
