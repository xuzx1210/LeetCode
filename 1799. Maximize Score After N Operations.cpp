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
                if (visited[prevMask] == false) // skip if not possible to reach
                    continue;
                visited[prevMask] = false;
                for (int i = 0; i < size; ++i)
                {
                    const int iMask = 1 << i;
                    if ((prevMask & iMask) != 0) // skip if nums[i] is chosen
                        continue;
                    for (int j = i + 1; j < size; ++j)
                    {
                        const int jMask = 1 << j;
                        if ((prevMask & jMask) != 0) // skip if nums[j] is chosen
                            continue;
                        const int currMask = prevMask | iMask | jMask;
                        visited[currMask] = true;
                        dp[currMask] = max(dp[currMask], dp[prevMask] + op * gcd(nums[i], nums[j]));
                    }
                }
            }
        return dp.back();
    }
};
