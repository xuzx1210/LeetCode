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

class Solution
{
private:
    int size, n, maskSize;
    vector<vector<int>> dp;
    int dfs(const int op, const int mask, vector<int> &nums)
    {                // op: current operation (0-indexed), mask: mask of chosen nums
        if (op == n) // all nums are chosen
            return 0;
        if (dp[op][mask] != 0) // visited
            return dp[op][mask];
        for (int i = 0; i < size; ++i)
        {
            const int iMask = 1 << i;
            if ((mask & iMask) != 0) // if nums[i] is chosen
                continue;
            for (int j = i + 1; j < size; ++j)
            {
                const int jMask = 1 << j;
                if ((mask & jMask) != 0) // if nums[j] is chosen
                    continue;
                const int nextMask = mask | iMask | jMask;
                const int score = dfs(op + 1, nextMask, nums) + (op + 1) * gcd(nums[i], nums[j]);
                dp[op][mask] = max(dp[op][mask], score); // save best score
            }
        }
        return dp[op][mask];
    }

public:
    int maxScore(vector<int> &nums)
    {
        size = nums.size();
        n = size >> 1;
        maskSize = 1 << size;
        dp.resize(n, vector<int>(maskSize, 0));
        return dfs(0, 0, nums);
    }
};
