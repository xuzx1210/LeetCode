class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, vector<int>>> dp(size);
        for (int i = 0; i < size; ++i)
            dp[i] = {1, {nums[i]}};
        int maximum = 0;
        vector<int> result;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
                if (!(nums[i] % nums[j]) && dp[j].first + 1 > dp[i].first)
                {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = dp[j].second;
                    dp[i].second.emplace_back(nums[i]);
                }
            if (dp[i].first > maximum)
            {
                maximum = dp[i].first;
                result = dp[i].second;
            }
        }
        return result;
    }
};
