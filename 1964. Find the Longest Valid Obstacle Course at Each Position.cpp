class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> ans{}, monotonic{};
        for (const int obstacle : obstacles)
        {
            int left = 0, right = monotonic.size();
            while (left < right)
            {
                const int middle = (left + right) >> 1;
                if (monotonic[middle] <= obstacle)
                    left = middle + 1;
                else
                    right = middle;
            }
            ans.emplace_back(left + 1);
            if (left == monotonic.size())
                monotonic.emplace_back(obstacle);
            monotonic[left] = obstacle;
        }
        return ans;
    }
};
