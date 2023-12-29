class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        const int size = jobDifficulty.size();
        if (size < d)
            return -1;
        vector<int> dp(size, 1000);
        for (int days = 0; days < d; ++days)
        {
            vector<int> tmp(size);
            stack<int> monotonic{};
            for (int jobs = days; jobs < size; jobs++)
            {
                tmp[jobs] = jobDifficulty[jobs];
                if (jobs)
                    tmp[jobs] += dp[jobs - 1];
                while (!monotonic.empty() && jobDifficulty[monotonic.top()] <= jobDifficulty[jobs])
                {
                    tmp[jobs] = min(tmp[jobs], tmp[monotonic.top()] - jobDifficulty[monotonic.top()] + jobDifficulty[jobs]);
                    monotonic.pop();
                }
                if (!monotonic.empty())
                    tmp[jobs] = min(tmp[jobs], tmp[monotonic.top()]);
                monotonic.emplace(jobs);
            }
            swap(dp, tmp);
        }
        return dp[size - 1];
    }
};
