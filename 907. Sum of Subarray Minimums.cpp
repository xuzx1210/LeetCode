class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int result = 0;
        const int size = arr.size(), mod = 1000000007;
        vector<int> dp(size);
        stack<int> monotonic{};
        for (int i = 0; i < size; ++i)
        {
            while (!monotonic.empty() && arr[monotonic.top()] >= arr[i])
                monotonic.pop();
            dp[i] = monotonic.empty() ? (i + 1) * arr[i] : (dp[monotonic.top()] + (i - monotonic.top()) * arr[i]) % mod;
            monotonic.emplace(i);
        }
        for (const int &num : dp)
            result = (result + num) % mod;
        return result;
    }
};
