class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        const int size = nums.size(), n = size >> 1, maskSize = 1 << size;
        vector<int> dp(maskSize, 0);
        vector<bool> visited(maskSize, false);
        visited[0] = true;
        for (int op = 1; op <= n; ++op)
            for (int prevMask = maskSize - 1; prevMask >= 0; --prevMask)
            {
                if (!visited[prevMask])
                    continue;
                visited[prevMask] = false;
                for (int i = size - 1; i >= 0; --i)
                {
                    const int iMask = 1 << i;
                    if (prevMask & iMask)
                        continue;
                    for (int j = i - 1; j >= 0; --j)
                    {
                        const int jMask = 1 << j;
                        if (prevMask & jMask)
                            continue;
                        const int currMask = prevMask | iMask | jMask;
                        visited[currMask] = true;
                        dp[currMask] = max(dp[currMask], dp[prevMask] + op * gcd(nums[i], nums[j]));
                    }
                }
            }
        return dp[maskSize - 1];
    }
};
