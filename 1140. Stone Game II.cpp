class Solution
{
private:
    int size;
    vector<vector<int>> dp;
    vector<int> suffixSum;
    int dfs(const int begin, const int M)
    {
        if (size <= begin + (M << 1))
            return suffixSum[begin];
        int &result = dp[begin][M];
        if (result)
            return result;
        for (int X = 1; X <= (M << 1); ++X)
            result = max(result, suffixSum[begin] - dfs(begin + X, max(M, X)));
        return result;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        size = piles.size();
        dp.resize(size, vector<int>(size, 0));
        suffixSum = piles;
        for (int i = size - 2; i >= 0; --i)
            suffixSum[i] += suffixSum[i + 1];
        return dfs(0, 1);
    }
};
