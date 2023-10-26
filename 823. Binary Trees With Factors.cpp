class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int result = 0;
        const int mod = 1000000007;
        const int size = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(size, 1);
        for (int i = 0; i < size; ++i)
        {
            for (int left = 0, right = i - 1; left <= right;)
            {
                long product = (long)arr[left] * arr[right];
                if (product < arr[i])
                    ++left;
                else if (arr[i] < product)
                    --right;
                else
                {
                    long coefficient = left == right ? 1 : 2;
                    dp[i] = (dp[i] + coefficient * dp[left] * dp[right]) % mod;
                    ++left;
                    --right;
                }
            }
            result = (result + dp[i]) % mod;
        }
        return result;
    }
};
