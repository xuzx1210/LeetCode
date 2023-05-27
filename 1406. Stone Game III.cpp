class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        const int size = stoneValue.size();
        vector<int> suffixSum(stoneValue);
        for (int i = size - 2; i >= 0; --i)
            suffixSum[i] += suffixSum[i + 1];
        vector<int> dp(size + 3, INT_MIN);
        dp[size] = dp[size + 1] = dp[size + 2] = 0;
        for (int i = size - 1; i >= 0; --i)
            for (int j = i + 1; j <= i + 3; ++j)
                dp[i] = max(dp[i], suffixSum[i] - dp[j]);
        int alice = dp.front(), bob = suffixSum.front() - alice;
        if (alice > bob)
            return "Alice";
        if (bob > alice)
            return "Bob";
        return "Tie";
    }
};
