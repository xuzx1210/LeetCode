class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        const int length = s.length(), size = to_string(k).length() + 1, MOD = 1000000007;
        vector<int> dp(size, 0);
        dp[length % size] = 1;
        for (int i = length - 1; i >= 0; --i)
        {
            const int cur = i % size;
            dp[cur] = 0;
            if (s[i] == '0')
                continue;
            long num = 0;
            for (int j = i; j < length; ++j)
            {
                num = num * 10 + (s[j] - '0');
                if (num > k)
                    break;
                dp[cur] = (dp[cur] + dp[(j + 1) % size]) % MOD;
            }
        }
        return dp[0];
    }
};
