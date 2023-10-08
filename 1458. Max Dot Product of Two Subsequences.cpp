class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() < nums2.size())
            nums1.swap(nums2);
        const int size1 = nums1.size(), size2 = nums2.size();
        vector<int> dp(size2);
        for (int i = 0; i < size1; ++i)
            for (int j = 0, curr; j < size2; ++j)
            {
                const int prev = curr;
                curr = dp[j];
                dp[j] = nums1[i] * nums2[j];
                if (i && j)
                    dp[j] += max(prev, 0);
                if (i)
                    dp[j] = max(dp[j], curr);
                if (j)
                    dp[j] = max(dp[j], dp[j - 1]);
            }
        return dp.back();
    }
};
