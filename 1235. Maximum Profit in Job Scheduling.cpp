class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        size_t size = profit.size();
        vector<vector<int>> jobs;
        for (size_t i = 0; i < size; ++i)
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        sort(jobs.begin(), jobs.end()); // sort by end time
        map<int, int> dp{{0, 0}};
        for (vector<int> &job : jobs)
        {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2]; // find last job whose end time <= current start time
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};
