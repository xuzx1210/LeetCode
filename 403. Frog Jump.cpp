class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones[0] + 1 != stones[1])
            return false;
        const int size = stones.size();
        unordered_map<int, int> indices{};
        for (int i = 2; i < size; ++i)
            indices[stones[i]] = i;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        dp[1][1] = true;
        for (int index = 1; index < size - 1; ++index)
            for (int k = 1; k <= index + 1; ++k)
                if (dp[index][k])
                {
                    if (indices[stones[index] + k - 1])
                        dp[indices[stones[index] + k - 1]][k - 1] = true;
                    if (indices[stones[index] + k])
                        dp[indices[stones[index] + k]][k] = true;
                    if (indices[stones[index] + k + 1])
                        dp[indices[stones[index] + k + 1]][k + 1] = true;
                }
        for (int k = 1; k < size; ++k)
            if (dp.back()[k])
                return true;
        return false;
    }
};
