class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const size_t size = arr.size(), mod = 1000000007;
        stack<size_t> monotonic; // index
        vector<size_t> dp(size);
        for (size_t i = 0; i < size; ++i)
        {
            while (!monotonic.empty())
                if (arr[monotonic.top()] >= arr[i])
                    monotonic.pop();
                else
                    break;
            if (monotonic.empty())
                dp[i] = (i + 1) * arr[i];
            else
            {
                size_t prev = monotonic.top();
                dp[i] = dp[prev] + (i - prev) * arr[i];
            }
            monotonic.emplace(i);
        }
        size_t result = 0;
        for (size_t &num : dp)
            result = (result + num) % mod;
        return result;
    }
};
