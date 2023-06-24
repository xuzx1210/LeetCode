class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        unordered_map<int, int> dp{{0, 0}};
        for (const int rod : rods)
        {
            unordered_map<int, int> cur(dp);
            for (const auto &[diff, height] : cur)
            {
                dp[diff + rod] = max(dp[diff + rod], height);
                if (diff < rod)
                    dp[rod - diff] = max(dp[rod - diff], height + diff);
                else
                    dp[diff - rod] = max(dp[diff - rod], height + rod);
            }
        }
        return dp[0];
    }
};
