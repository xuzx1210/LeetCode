class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int mod = 1000000007;
        sort(arr.begin(), arr.end());
        int size = arr.size();
        vector<long long> dp(size, 1);
        int result = 1;
        for (int i = 1; i < size; ++i)
        {
            int left = 0, right = i - 1;
            while (left <= right)
            {
                long long cur = (long long)arr[left] * (long long)arr[right];
                if (cur < arr[i])
                    ++left;
                else if (cur > arr[i])
                    --right;
                else
                {
                    if (left == right)
                        dp[i] += dp[left] * dp[right];
                    else
                        dp[i] += 2 * dp[left] * dp[right];
                    dp[i] %= mod;
                    ++left;
                    --right;
                }
            }
            result = (result + dp[i]) % mod;
        }
        return result;
    }
};
