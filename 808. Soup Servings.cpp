class Solution
{
private:
    vector<vector<double>> memo;
    double dp(int a, int b)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        if (memo[a][b] > 0)
            return memo[a][b];
        memo[a][b] = 0.25 * (dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3));
        return memo[a][b];
    }

public:
    double soupServings(int N)
    {
        if (4450 < N)
            return 1.0;
        N = (N + 24) / 25;
        memo.resize(N + 1, vector<double>(N + 1, 0.0));
        return dp(N, N);
    }
};
