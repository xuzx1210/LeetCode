class Solution
{
private:
    int rows, cols, divisor;
    vector<vector<vector<int>>> dp; // result of [cuts][r][c]
    vector<vector<int>> prefixSum;  // apples of bottom left
    int dfs(int remainCuts, int r, int c)
    {
        if (prefixSum[r][c] <= remainCuts) // apples not enough for cuts
            return 0;
        if (remainCuts == 0) // no need to cut anymore
            return 1;
        if (dp[remainCuts][r][c] != -1) // if visited before
            return dp[remainCuts][r][c];
        int result = 0;
        for (int cut = rows - 1; cut > r && prefixSum[cut][c] < prefixSum[r][c]; --cut)
            result = (result + dfs(remainCuts - 1, cut, c)) % divisor;
        for (int cut = cols - 1; cut > c && prefixSum[r][cut] < prefixSum[r][c]; --cut)
            result = (result + dfs(remainCuts - 1, r, cut)) % divisor;
        dp[remainCuts][r][c] = result; // store result for next time
        return result;
    }

public:
    int ways(vector<string> &pizza, int k)
    {
        rows = pizza.size();
        cols = pizza.front().size();
        divisor = 1000000007;
        dp.resize(k, vector<vector<int>>(rows, vector<int>(cols, -1)));
        prefixSum.resize(rows + 1, vector<int>(cols + 1, 0));
        for (int r = rows - 1; r >= 0; --r)
            for (int c = cols - 1; c >= 0; --c)
            {
                prefixSum[r][c] = prefixSum[r + 1][c] + prefixSum[r][c + 1] - prefixSum[r + 1][c + 1];
                if (pizza[r][c] == 'A')
                    ++prefixSum[r][c];
            }
        return dfs(k - 1, 0, 0);
    }
};
