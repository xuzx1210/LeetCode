class Solution
{
public:
    int ways(vector<string> &pizza, int k)
    {
        const int rows = pizza.size(), cols = pizza.front().size(), divisor = 1000000007;
        // prefixSum[r][c]: how many apples are located at bottom right corner of (r, c)
        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));
        for (int r = rows - 1; r >= 0; --r)
            for (int c = cols - 1; c >= 0; --c)
            {
                prefixSum[r][c] = prefixSum[r + 1][c] + prefixSum[r][c + 1] - prefixSum[r + 1][c + 1];
                if (pizza[r][c] == 'A')
                    ++prefixSum[r][c];
            }
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // cuts = 0
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (prefixSum[r][c])
                    dp[r][c] = 1;
        for (int cuts = 1; cuts < k; ++cuts)
        {
            vector<vector<int>> buffer(rows, vector<int>(cols, 0));
            for (int r = 0; r < rows; ++r)
                for (int c = 0; c < cols; ++c)
                {
                    if (prefixSum[r][c] <= cuts)
                        continue;
                    for (int cut = rows - 1; cut > r && prefixSum[cut][c] < prefixSum[r][c]; --cut)
                        buffer[r][c] = (buffer[r][c] + dp[cut][c]) % divisor;
                    for (int cut = cols - 1; cut > c && prefixSum[r][cut] < prefixSum[r][c]; --cut)
                        buffer[r][c] = (buffer[r][c] + dp[r][cut]) % divisor;
                }
            dp = buffer;
        }
        return dp.front().front();
    }
};
