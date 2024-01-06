class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> jobs{};
        for (int i = startTime.size() - 1; i >= 0; --i)
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        map<int, int> dp{{0, 0}};
        for (const vector<int> &job : jobs)
        {
            const int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (dp.rbegin()->second < cur)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};
