class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones[0] + 1 != stones[1])
            return false;
        const size_t size = stones.size();
        vector<set<int>> dp(size);
        dp[1].emplace(1);
        for (size_t i = 2; i < size; ++i)
            for (size_t j = 1; j < i; ++j)
            {
                const int diff = stones[i] - stones[j];
                for (int k : dp[j])
                    if (k - 1 <= diff && diff <= k + 1)
                    {
                        dp[i].emplace(diff);
                        break;
                    }
            }
        return !dp.back().empty();
    }
};
